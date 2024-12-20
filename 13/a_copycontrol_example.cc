#include <iostream>
#include <string>
#include <set>
#include <iterator>
using std::cout;
using std::endl;
using std::string;
class Message;
class Folder
{
public:
    void addMsg(Message *);
    void remMsg(Message *);
    inline void print();

private:
    std::set<Message *> messages;
};
void Folder::addMsg(Message *p)
{
    messages.insert(p);
}
void Folder::remMsg(Message *p)
{
    messages.erase(p);
}

class Message
{
    friend class Folder;
    friend inline void swap(Message &, Message &);

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) {}
    // copy control to manage pointers to this Message
    Message(const Message &); // copy constructor

    // assignment
    //  Message &operator=(const Message &); // copy assignment

    // 改成swap copy assignment
    Message &operator=(Message); // copy assignment

    ~Message(); // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);
    string getContent()
    {
        return contents;
    }

private:
    std::string contents;       // actual message text
    std::set<Folder *> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders();
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};
Message::~Message()
{
    remove_from_Folders();
}
void Message::save(Folder &f)
{
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // add this Message to f's set of Messages
}

void Message::remove(Folder &f)
{
    folders.erase(&f); // take the given Folder out of our list of Folders
    f.remMsg(this);    // remove this Message to f's set of Messages
}

// add this Message to Folders that point to m
void Message::add_to_Folders()
{
    for (auto f : folders) // for each Folder that holds m
        f->addMsg(this);   // add a pointer to this Message to that Folder
}
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(); // add this Message to the Folders that point to m
}
// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

// Message &Message::operator=(const Message &rhs)
// {
//     // handle self-assignment by removing pointers before inserting them
//     remove_from_Folders();   // update existing Folders
//     contents = rhs.contents; // copy message contents from rhs
//     folders = rhs.folders;   // copy Folder pointers from rhs
//     add_to_Folders();        // add this Message to those Folders
//     return *this;
// }

void swap(Message &lhs, Message &rhs)
{
    using std::swap; // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    // for (auto f : lhs.folders)
    //     f->remMsg(&lhs);
    // for (auto f : rhs.folders)
    //     f->remMsg(&rhs);
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);   // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents); // swap(string&, string&)

    // add pointers to each Message to their (new) respective Folders
    // for (auto f : lhs.folders)
    //     f->addMsg(&lhs);
    // for (auto f : rhs.folders)
    //     f->addMsg(&rhs);
    lhs.add_to_Folders();
    rhs.add_to_Folders();
}

Message &Message::operator=(Message rhs)
{
    swap(*this, rhs);
    return *this;
}

void Folder::print()
{
    for (auto i : messages)
    {
        cout << i->getContent() << " ";
    }
    cout << endl;
}
int main()
{
    Folder f1, f2;
    Message m1("hello"), m2("world"), m3;
    m1.save(f1);
    m1.save(f2);
    m2.save(f1);
    m2.save(f2);
    m3 = m1;
    cout << "m1: " << m1.getContent() << "  "
         << "m2: " << m2.getContent() << "  "
         << "m3: " << m3.getContent() << "  "
         << endl;
    f1.print();
    f2.print();

    string::reverse_iterator it;
    return 0;
}