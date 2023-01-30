# include <iostream>
# include <string>
#include<time.h>
using namespace std;
# include <algorithm>
class Transaction {
    int transactionID;
    string transactionName;
    string transactionDate;
public:
    Transaction() {};
    Transaction(int id, string name, string date) {
        transactionID = id;
        transactionDate = date;
        transactionName = name;
    }
    void settransactionID(int id) {
        transactionID = id;
    }
    int gettransactionID() {
        return transactionID;
    }
    void settransactionName(string name) {
        transactionName = name;
    }
    string gettransactionName() {
        return transactionName;
    }
    void settransactionDate(string date) {
        transactionDate = date;
    }
    string gettransactionDate() {
        return transactionDate;
    }
    void viewtran();
};
void Transaction::viewtran() {
    cout << "the transaction name:" << gettransactionName() << endl;
    cout << "the transaction id:" << gettransactionID() << endl;
    cout << "the transaction date:" << gettransactionDate() << endl;
}
class Client {
    string clientEmail;
    string clientName;
    string clientPhone;
    string clientAddress;
    string clientPassword;
    int clientID;
public:
    Transaction array[5];
    int size = 0;
    Client() {};
    Client(string email, string name, string phone, string address, string password, int id) {
        clientAddress = address;
        clientEmail = email;
        clientPhone = phone;
        clientName = name;
        clientPassword = password;
        clientID = id;
    }
    void setclientEmail(string email) {
        clientEmail = email;
    }
    string getclientEmail() {
        return clientEmail;
    }
    void setclientName(string name) {
        clientName = name;
    }
    string getclientName() {
        return clientName;
    }
    void setclientPhone(string phone) {
        clientPhone = phone;
    }
    string getclientPhone() {
        return clientPhone;
    }
    void setclientAddress(string address) {
        clientAddress = address;
    }
    string getclientAddress() {
        return clientAddress;
    }
    void setclientPassword(string password) {
        clientPassword = password;
    }
    string getclientPassword() {
        return clientPassword;
    }
    void setclientID(int id) {
        clientID = id;
    }
    int getclientID() {
        return clientID;
    }
    void print_info();
};
void Client::print_info() {
    cout << "the client name:" << getclientName() << endl;
    cout << "the client address:" << getclientAddress() << endl;
    cout << "the client email:" << getclientEmail() << endl;
    cout << "the client phone:" << getclientPhone() << endl;
    cout << "the client id:" << getclientID() << endl;
}
class LinkedListNode {
public:
    Client data; // CLIENT type 
    LinkedListNode* next;
    LinkedListNode(Client data_input) {
        data = data_input;
        next = NULL;
    }
};
class ClientsLinkedList {
    // to use in the sort process
public:
    LinkedListNode* head;
    int listsize;
    ClientsLinkedList() {
        head = NULL;
        listsize = 0;
    }
    bool insert(Client c);
};
bool ClientsLinkedList::insert(Client c) {
    LinkedListNode* newNode = new LinkedListNode(c);
    if (head == NULL) {
        head = newNode;
        listsize++;
        return true;
    }
    LinkedListNode* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data.getclientEmail() == newNode->data.getclientEmail())
        {
            cout << "the email already exist" << endl;
            return false;
        }
        tmp = tmp->next;
    }
    LinkedListNode* tmp1 = head;

    while (tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    tmp1->next = newNode;
    listsize++;
    return true;
}
void delete_element(Transaction array[5], int& size, int id) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (array[i].gettransactionID() == id) {
            for (j = i; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            return;
        }
        else {
            cout << "Invalid ID" << endl;
        }
    }
}
void transactionmenu() {
    int i, choice = 0;
    Client c;
    c.size = 0;
    while (true) {
        cout << "Welcome in transaction menu" << endl;
        cout << "1-make a transaction" << endl;
        cout << "2-view transaction" << endl;
        cout << "3-delete from transaction" << endl;
        cout << "4-Exit" << endl;
        cout << "enter your choice" << endl;
        cin >> choice;
        if (choice == 1) {
            c.size++;
            for (i = 0; i < c.size; i++) {
                if (c.size > 5)
                {
                    cout << "you can only make 5 transaction" << endl;
                    break;
                }
                Transaction t(i, "name", "date");
                c.array[i] = t;
                cout << "done" << endl;
            }
        }
        if (choice == 2) {
            if (c.size == 6)
            {
                c.size--;
            }
            if (c.size == 0)
            {
                cout << "the transction is empty " << endl;
            }
            for (int j = 0; j < c.size; j++)
            {
                cout << "this is your transaction" << endl;
                c.array[j].viewtran();
                cout << "done" << endl;
                cout << "****" << endl;
            }
        }
        if (choice == 3)
        {
            if (c.size == 6)
            {
                c.size--;
            }
            if (c.size == 0)
            {
                cout << "the transaction is empty " << endl;
            }
            if (c.size != 0)
            {
                int id;
                cout << "enter the id you want to delete" << endl;
                cin >> id;
                delete_element(c.array, c.size, id);
            }
        }
        if (choice == 4)
        {
            break;
        }
    }
}
void information(int i, ClientsLinkedList array[10])
{
    LinkedListNode* tmp = array[i].head;
    tmp->data.print_info();
}
// Function to partition the array and return the partition index
int partition(ClientsLinkedList arr[10], int low, int high) {
    int pivot = arr[high].listsize;  // select last element as pivot
    int i = (low - 1);  // index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // if current element is smaller than or equal to pivot
        if (arr[j].listsize <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
//low  --> Starting index, high  --> Ending index 
void quickSort(ClientsLinkedList arr[], int low, int high) {
    if (low < high) {
        //pi is partitioning index, arr[p] is now at right place 
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(ClientsLinkedList arr[10]) {
    for (int i = 0; i < 10; i++)
        cout << arr[i].listsize << " ";
    cout << endl;
}
string mainmenu(ClientsLinkedList array[10]) {
    string choose;
    cout << "++++++++++++++++++++++++++Welcome to the banking system+++++++++++++++++++++++++++++ " << endl;
    cout << endl << "Choose one of the following option" << endl;
    cout << "1.Login to your account" << endl;
    cout << "2.New Client ?" << endl;
    cout << "3.Forgot your password ? " << endl;
    cout << "4.Sort clients by linked list size using the quick sort algorithim" << endl;
    cout << "5.sorted by clients' ID" << endl;
    cout << "6.Exit the program" << endl;
    cout << ">>entre please the option: " << endl;
    cin >> choose;
    return choose;
}
void clienthome(int i, ClientsLinkedList array[10]) {
    int number;
    while (true) {
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "++++++++++++++++++++++++++Welcome to the banking system+++++++++++++++++++++++++++++ " << endl;
        cout << "++++++++++++++++++++++++++++++Welcome to the home page++++++++++++++++++++++++++++++++++" << endl;
        cout << "Choose one of the following option" << endl;
        cout << "1.transaction menu " << endl;
        cout << "2.view personal info" << endl;
        cout << "3.logout " << endl;
        cout << ">> ";
        cin >> number;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        if (number == 1) {
            transactionmenu();
        }
        if (number == 2) {
            information(i, array);
        }
        if (number == 3) {
            break;
        }
    }
}
void loginmenu(ClientsLinkedList array[10]) {
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "++++++++++++++++++++++++++Welcome to the banking system+++++++++++++++++++++++++++++ " << endl;
    cout << "++++++++++++++++++++++++++++++Welcome back dear client++++++++++++++++++++++++++++++" << endl;
    string email, password;
    cout << "Please write your email" << endl;
    cout << ">>";
    cin >> email;
    cout << "Please write your password" << endl;
    cout << ">>";
    cin >> password;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    bool check = true;
    int x = 0;
    int z = 0;
    for (int i = 0; i < 10; i++) {
        LinkedListNode* tmp = array[i].head;
        while (tmp != NULL) {
            if (tmp->data.getclientEmail() == email && tmp->data.getclientPassword() == password) {
                x = i;
                check = false;
                break;
            }
            else if (tmp->data.getclientEmail() != email && tmp->data.getclientPassword() == password || tmp->data.getclientEmail() == email && tmp->data.getclientPassword() != password) {
                check = true;
                z = 2;
                break;
            }
            else if (tmp->data.getclientEmail() != email && tmp->data.getclientPassword() != password) {
                if (tmp->next == NULL) {
                    check = true;
                    z = 10;
                    break;
                }
            }
            tmp = tmp->next;
        }
        if (check == false) {
            break;
        }
        if (check == true && z == 2) {
            break;
        }
        if (z == 10) {
            continue;
        }
    }
    if (check == false) {
        cout << "correct" << endl;
        clienthome(x, array);
    }
    else {
        if (check == true && z == 0) {
            cout << "EMPTY-LIST" << endl;
        }
        else if (z == 10) {
            cout << "In_correct" << endl;
        }
        else if (check == true && z == 2) {
            cout << "In-correct" << endl;
        }
    }
}
int random_function() {
    bool choice = false;
    if (!choice) {
        srand((unsigned)time(NULL));
        choice = true;
    }
    return rand();
}
void newclientmenu(ClientsLinkedList array[10]) {
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++Welcome to the banking system++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++Create a new client account ++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string name;
    cout << "Please write your name" << endl;
    cout << ">>" << endl;
    cin >> name;
    string email;
    cout << "Please write your email" << endl;
    cout << ">>" << endl;
    cin >> email;
    string phone;
    cout << "Please write your phone" << endl;
    cout << ">>" << endl;
    cin >> phone;
    string pass;
    cout << "Please write your password" << endl;
    cout << ">>" << endl;
    cin >> pass;
    string address;
    cout << "Please write your address" << endl;
    cout << ">>" << endl;
    cin >> address;
    int id;
    id = random_function();
    int index = id % 10;
    Client c1(email, name, phone, address, pass, id);
    bool x = false;
    for (int i = 0; i < 10; i++) {
        LinkedListNode* tmp = array[i].head;
        while (tmp != NULL) {
            if (tmp->data.getclientEmail() == email) {
                cout << "this email already taken  " << endl;
                x = true;
                break;
            }
            tmp = tmp->next;
        }
    }
    if (x == false) {
        array[index].insert(c1);
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
void forget_password(ClientsLinkedList array[10]) {
    string email;
    cout << "entre the valid email" << endl;
    cin >> email;
    LinkedListNode* tmp1;
    for (int i = 0; i < 10; i++) {
        LinkedListNode* tmp = array[i].head;
        while (tmp != NULL) {
            if (tmp->data.getclientEmail() == email) {
                cout << "your password is:" << tmp->data.getclientPassword() << endl;
                break;
            }
            tmp = tmp->next;
        }
    }
}
void bubble_sort(int listsize[10], LinkedListNode* sort, int s) {
    for (int j = 0; j < listsize[s] - 1; ++j) {
        for (int i = 0; i < listsize[s] - j - 1; ++i) {
            if (sort->data.getclientID() > sort->next->data.getclientID()) {
                Client temp = sort->data;
                sort->data = sort->next->data;
                sort->next->data = temp;
            }
        }
    }
}
void SortIDs(ClientsLinkedList arr[10]) {
    LinkedListNode* tmp = arr[10].head;
    int listsize[10];
    for (int i = 0; i < 10; i++) {
        listsize[i] = 0;
        while (tmp != NULL) {
            listsize[i]++;
            tmp = tmp->next;
        }
    }
    LinkedListNode* sort = arr[10].head;
    for (int s = 0; s < 10; s++) {
        while (sort != NULL) {
            bubble_sort(listsize, sort, s);
        }
    }
    for (int i = 0; i < 10; i++) {
        LinkedListNode* tmp = arr[i].head;
        cout << "Line Output: " << i << endl;
        while (tmp != NULL) {
            tmp->data.print_info();
            tmp = tmp->next;
        }
    }
}
void printall(ClientsLinkedList arr[10]) {
    for (int i = 0; i < 10; i++) {
        LinkedListNode* tmp = arr[i].head;
        cout << "Line Output: " << i << endl;
        while (tmp != NULL) {
            tmp->data.print_info();
            tmp = tmp->next;
        }
        cout << "==========" << endl;
    }
}
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
int main() {
    ClientsLinkedList array[10];
    while (true) {
        string x = mainmenu(array);
        if (!isNumber(x)) {
            cout << "IN_Valid option it should be number!" << endl;
            continue;
        }
        if (x == "1") {
            loginmenu(array);
        }
        if (x == "2") {
            newclientmenu(array);
        }
        if (x == "3") {
            cout << "forget password" << endl;
            forget_password(array);
        }
        if (x == "4") {
            cout << "sort the client " << endl;
            quickSort(array, 0, 10 - 1);
            cout << "Sorted array: \n";
            printArray(array);
        }
        if (x == "5") {
            SortIDs(array);
            cout << "Sorted array by clients' ID: \n";
        }
        if (x == "6") {
            cout << "EXIT the program" << endl;
            break;
        }
    }
    return 0;
}