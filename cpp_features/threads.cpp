/// std threads with lock guards scope which gets destroyed in destructor of it.
#include <iostream>
#include <mutex>
#include <thread>

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string& thread_name) {
  ++rage;  // modifying outside a lock is okay; this is a thread-local variable
  std::lock_guard<std::mutex> lock(cout_mutex);
  std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}

int main() {
  std::thread a(increase_rage, "a"), b(increase_rage, "b"),
      c(increase_rage, "c");

  {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Rage counter for main: " << rage << '\n';
  }

  a.join();
  b.join();
  c.join();
}