#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c, Node* nextNode = nullptr) : data(c), next(nextNode) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    Node* curr;
public:
    LinkedList() {
        head = new Node('\0'); // head da lista
        tail = head;
        curr = tail;
    }

    ~LinkedList() {
        clear();
        delete head;
    }

    void insert(char c) {
        curr->next = new Node(c, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
    }

    void moveToStart() {
        curr = head;
    }

    void moveToEnd() {
        curr = tail;
    }

    void moveRight() {
        if (curr != tail) {
            curr = curr->next;
        }
    }

    void printList() {
        string contrario;
        Node* current = head->next;

        while (current != nullptr) {
            contrario+= current->data;
            current = current->next;
        }
        for(int i=contrario.length()-1; i>=0; i--){
            cout <<contrario[i];
        }
    }

    void clear() {
        while (head->next != nullptr) {
            Node* temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        tail = head;
        curr = tail;
    }
};

// Função para processar uma linha de texto
void processLine(const string& frase) {
    LinkedList texto;

    for (int i = 0; i < frase.size(); ++i) {
        if (frase[i] == '[')
            texto.moveToEnd();
        else if (frase[i] == ']')
            texto.moveToStart();
        else
            texto.insert(frase[i]);
    }

    texto.printList();
    cout << endl;
}

int main() {
    string frase;

    while (getline(cin, frase)) {
        processLine(frase);
    }

    return 0;
}
