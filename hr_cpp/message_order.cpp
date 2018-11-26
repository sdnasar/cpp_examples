/// order the entered message which was shuffeled randomly
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Message {
 public:
  Message() {}
  Message(string s, int messageIndex) {
    _messageIndex = messageIndex;
    _message = s;
  }
  const string& get_text() { return _message; }
  bool operator<(const Message& m) const {
    return this->_messageIndex < m._messageIndex;
  }

 private:
  int _messageIndex;
  string _message;
};

class MessageFactory {
 public:
  MessageFactory() { _messageIndex = 0; }
  Message create_message(const string& text) {
    return Message(text, _messageIndex++);
  }

 private:
  int _messageIndex;
};

class Recipient {
 public:
  Recipient() {}
  void receive(const Message& msg) { messages_.push_back(msg); }
  void print_messages() {
    fix_order();
    for (auto& msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }

 private:
  void fix_order() { sort(messages_.begin(), messages_.end()); }
  vector<Message> messages_;
};

class Network {
 public:
  static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in
    // unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};

int main() {
  MessageFactory message_factory;
  Recipient recipient;
  vector<Message> messages;
  string text;
  while (getline(cin, text)) {
    messages.push_back(message_factory.create_message(text));
  }
  Network::send_messages(messages, recipient);
  recipient.print_messages();
}
