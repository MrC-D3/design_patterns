#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <stack>


using namespace std;

string to_string(deque<string>& linked_list)
{
    string to_return;
    for(auto& node : linked_list)
    {
        to_return += (node + " ");
    }
    return to_return;
}
string to_string(multiset<string>& linked_list)
{
    string to_return;
    for(auto& node : linked_list)
    {
        to_return += (node + " ");
    }
    return to_return;
}

// Hierholzer's algorithm for Eulerian path.
class Solution 
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        // A map is ordered: no need here and lookup costs LogN instead of 1.
        unordered_map<string, multiset<string>> from_to;
        for(const auto& ticket : tickets)
        {
            from_to[ticket[0]].insert(ticket[1]);
        }

        // A vector is better for cache locality (contiguous memory) than deque
        //  and allows to use index instead of iterators: less overhead.
        vector<string> result{tickets.size()+1, ""};
        int i = result.size()-1;

        // A stack uses less overhead than a recursive solution.
        stack<string> to_process;
        to_process.push("JFK");
        while (!to_process.empty())
        {
            auto from = to_process.top();
            if (from_to.find(from) == from_to.end() || from_to[from].empty())
            {
                result[i--] = from;
                to_process.pop();
                continue;
            }

            // Use a reversed sorted vector<> and call back() and pop_back() 
            //  instead of a multiset<> and erase() because: 
            //  1. better memory layout (cache locality);
            //  2. erase() costs LogN because the multiset<> is reordered, while
            //   pop_back() costs 1.
            auto to = from_to[from].begin();
            to_process.push(*to);
            from_to[from].erase(to);
        }

        return result;
    }
};

// O(N∗Mlog(M)).
class Solution_v1
{
public:
    bool findNext(map<string, multiset<string>>& from_to, const string& from, deque<string>& itinerary, deque<string>::iterator& it, int count_to_reach)
    {
        cout << "Empty? " << from_to[from].empty() << endl;

        if (from_to.find(from) == from_to.end() || from_to[from].empty())
        {
            // Here if you found the very last destination.
            //  Now check if you also found the complete itinerary.
            if (itinerary.size() == count_to_reach)
            {
                // Here if you also found the complete itinerary.
                return true;
            }
            else
            {
                // Here if found only the the last destination.
                //  So, build the itinerary backward!
                return false;
            }
        }

        do
        {
            auto it_destination = from_to[from].begin();
            auto destination = *it_destination;
            cout << from << "-" << destination << endl;

            // Destination not removed.
            it = itinerary.insert(it, destination);
            from_to[from].erase(it_destination);
            cout << "  Itinerary " << to_string(itinerary) << endl;
            cout << "  Destinations " << to_string(from_to[from]) << endl;
            
            if (findNext(from_to, destination, itinerary, ++it, count_to_reach))
            {
                return true;
            }
            
            cout << "  Rollback after " << from << "-" << destination << endl;
            --it;
        } while (!from_to[from].empty());

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        // Hash map built on tickets[i][0]. Destinations ordered in set.
        map<string, multiset<string>> from_to;
        for (int i  = 0; i < tickets.size(); i++)
        {
            from_to[tickets[i][0]].emplace(tickets[i][1]);
        }

        // deque<T> is a linked list, while list<T> is an array.
        deque<string> itinerary;
        auto it = itinerary.end();
        // Iterator is invalidated after insert().
        it = itinerary.insert(it, "JFK");
        // Scan on "JFK"'s multiset and then recursively.
        findNext(from_to, "JFK", itinerary, ++it, tickets.size()+1);

        // From deque<T> to vector<T>.
        vector<string> to_return{itinerary.begin(), itinerary.end()};

        return to_return;
    }
};

int main()
{
    //vector<vector<string>> tickets{{"JFK","SFO"},{"JFK","ATL"},{"SFO","JFK"},
    //{"ATL","AAA"},{"AAA","ATL"},{"ATL","BBB"},{"BBB","ATL"},{"ATL","CCC"},
    //{"CCC","ATL"},{"ATL","DDD"},{"DDD","ATL"},{"ATL","EEE"},{"EEE","ATL"},
    //{"ATL","FFF"},{"FFF","ATL"},{"ATL","GGG"},{"GGG","ATL"},{"ATL","HHH"},
    //{"HHH","ATL"},{"ATL","III"},{"III","ATL"},{"ATL","JJJ"},{"JJJ","ATL"},
    //{"ATL","KKK"},{"KKK","ATL"},{"ATL","LLL"},{"LLL","ATL"},{"ATL","MMM"},
    //{"MMM","ATL"},{"ATL","NNN"},{"NNN","ATL"}};
    vector<vector<string>> tickets{{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},
      {"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},
      {"ANU","TIA"},{"JFK","TIA"}};
    
    Solution s;
    auto solution = s.findItinerary(tickets);

    std::cout << "Itenerary: ";
    for(auto step : solution)
    {
        std::cout << step << " ";
    }
    std::cout << std::endl;

    return 0;
}
