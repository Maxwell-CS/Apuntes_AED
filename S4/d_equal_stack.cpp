#include<bits/stdc++.h>
using namespace::std;
template<typename data_type>
struct Queue {
    struct QueueNode {
        data_type data;
        QueueNode* next;
        QueueNode() {
        }
        QueueNode(data_type data) : data(data), next(nullptr) {}
    };
    QueueNode* _front, *_back;
    Queue() {
        _front = nullptr;
        _back = nullptr;
    }
    void push(data_type value) {
        if (_front == nullptr) {
            _front = new QueueNode(value);
            _back = _front;
        }
        else {
            _back->next = new QueueNode(value);
            _back = _back -> next;
        }
    }
    void pop() {
        if (_front != nullptr) {
            _front = _front -> next;
        }
    }
    data_type front() {
        return _front == nullptr ? data_type() : _front -> data;
    }
    bool empty() {
        return _front == nullptr;
    }
};
int main() {
    int n, m, q;
    int x;
    cin >> n >> m >> q;
    Queue<int> Q1;
    Queue<int> Q2;
    Queue<int> Q3;

    long long t1 = 0,t2 = 0,t3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Q1.push(x);
        t1+=x;

    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        Q2.push(x);
        t2+=x;
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        Q3.push(x);
        t3+=x;
    }

    while (!(t1==t2 and t2==t3)) {
        long long m = max({t1,t2,t3});
        if (t1 == m) {
            t1 -= Q1.front();
            Q1.pop();
        }
        if (t2 == m) {
            t2 -= Q2.front();
            Q2.pop();
        }
        if (t3 == m) {
            t3 -= Q3.front();
            Q3.pop();
        }
    }
    cout <<t1;
    return 0;
}
