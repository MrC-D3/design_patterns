#include "05_observer/subject_interface.hpp"

#include <algorithm> // For std::remove_if().
#include <iostream>


namespace ObserverNS
{
    
void SubjectInterface::attach(const std::shared_ptr<ObserverInterface>& observer)
{
    std::cout << "I'm the Subject. Attaching a new Observer.\n";

    m_observers.push_back(observer);
    observer->store_subject( shared_from_this() );
}

void SubjectInterface::detach(const std::shared_ptr<ObserverInterface>& observer)
{
    std::cout << "I'm the Subject. Detaching the dying Observer.\n";

    // Cons of not using a loop: it goes over the whole container.
    // Pros: 
    //  - more readable, you know directly what's going to happen;
    //  - more generic, you can change the condition of erase();
    //  - delete any possible duplicates of observer. 
    m_observers.erase(
      std::remove_if(
        m_observers.begin(), m_observers.end(), 
        [&observer] (const std::weak_ptr<ObserverInterface>& o) 
        {
            if (auto obs = o.lock()) // std::shared_ptr<ObserverInterface>
            {
                return observer == obs;;
            }
            return false;
        }
      ),
      m_observers.end()
    );

    // To stop at 1st match:
    //  auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    //  if (it != m_observers.end()) m_observers.erase(it);
    // In case of C++20:
    //  std::erase_if(m_observers, [&observer](const auto& o) { return o == observer; });

}

void SubjectInterface::notify() const 
{
    std::cout << "I'm the Subject. Notifying the Observers about my change.\n";

    for (const auto& observer : m_observers)
    {
        if (auto obs = observer.lock()) // std::shared_ptr<ObserverInterface>
        {
            // The pattern is synchronous: if an update() is slow and blocks
            //  the Subject, use an event-queue pattern or add multi-threads.
            obs->update();
        }
    }
}


} // namespace ObserverNS