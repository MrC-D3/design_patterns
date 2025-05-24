#include "12_observer/subject_interface.hpp"

#include <algorithm> // For std::remove_if().


namespace ObserverNS
{
    
void SubjectInterface::attach(const std::shared_ptr<ObserverInterface>& observer)
{
    m_observers.push_back(observer);
    observer->store_subject( shared_from_this() );
}

void SubjectInterface::detach(const std::shared_ptr<ObserverInterface>& observer)
{
    // Cons of not using a loop: it goes over the whole container.
    // Pros: 
    //  - more readable, you know directly what's going to happen;
    //  - more generic, you can change the condition of erase();
    //  - delete any possible duplicates of observer. 
    m_observers.erase(
      std::remove_if(
        m_observers.begin(), m_observers.end(), 
        [&observer] (const std::shared_ptr<ObserverInterface>& o) 
        { return o == observer; }
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
    for (const auto& observer : m_observers)
    {
        observer->update();
    }
}


} // namespace ObserverNS