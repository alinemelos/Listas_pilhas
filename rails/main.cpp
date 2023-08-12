#include <cstdio>
#include <iostream>

const int MAX_N = 1000;

class Stack {
private:
    int arr[MAX_N + 1];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    bool empty() {
        return topIndex == -1;
    }

    void push(int val) {
        if (topIndex < MAX_N) {
            arr[++topIndex] = val;
        }
    }

    void pop() {
        if (!empty()) {
            --topIndex;
        }
    }

    int top() {
        if (!empty()) {
            return arr[topIndex];
        }
        return -1; // Indicating an empty stack
    }
};

int main() {
    // freopen("input.txt", "r", stdin);

    int N, i, coach, k;
    Stack station;

    while (true) {
        scanf("%d\n", &N);

        if (!N)
            break;

        while (true) {
            station = Stack();

            for (k = i = 0; i < N; i++) {
                scanf("%d ", &coach);

                if (!coach)
                    break;

                while (k < N && k != coach) {
                    if (!station.empty() && station.top() == coach)
                        break;

                    station.push(++k);
                }

                if (!station.empty() && station.top() == coach)
                    station.pop();

            }

            if (!coach)
                break;


            if (station.empty())
                printf("Yes\n");
            else
                printf("No\n");

        }

        printf("\n");
    }

    return 0;
}

