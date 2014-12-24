#pragma once

#include <cstring>
#include <vector>
#include <stack>

using std::size_t;
using std::strlen;
using std::vector;
using std::stack;

class Trie {
private:
    static size_t const LENGTH = 256;
    struct Vertex { 
        Vertex * vertex; 
        char * phone; 
        Vertex() : vertex(nullptr), phone(nullptr) {}
    };
    Vertex * head;

    unsigned char uchar(char a) { return (unsigned char)(a); }

    Trie(Trie const & a) {} 

    Trie const & operator=(Trie const & a) const { return *this; }
public:
    Trie() : head(new Vertex [LENGTH]) {}

    ~Trie() {
        stack<vector<Vertex *>> vert;

        vector<Vertex *> temp;

        for (size_t j{0}; j < LENGTH; ++j) {
            if (head[j].phone)
                delete [] head[j].phone;

            if (head[j].vertex) 
                temp.push_back(head[j].vertex);
        }

        while(!temp.empty()) {
            vert.push(temp);

            temp.clear();

            for (size_t i{0}; i < vert.top().size(); ++i) 
                for (size_t j{0}; j < LENGTH; ++j) {
                    if (vert.top()[i][j].phone)
                        delete [] vert.top()[i][j].phone;

                    if (vert.top()[i][j].vertex) 
                        temp.push_back(vert.top()[i][j].vertex);
                }
        }
        
        while (!vert.empty()) {
            for (size_t i{0}; i < vert.top().size(); ++i)
                delete [] vert.top()[i];

            vert.pop();
        }

        delete [] head;
    }    

    void add(char const * name, char const * phone) {
        size_t n = strlen(name);
        
        if (!n) {
            if (head[0].phone)
                delete [] head[0].phone;

            head[0].phone = new char [strlen(phone) + 1];
            strcpy(head[0].phone, phone);
            return;
        }

        Vertex * temp = head;
        
        for (size_t i{0}; i < n - 1; ++i) {
            if (!temp[uchar(name[i])].vertex)
                temp[uchar(name[i])].vertex = new Vertex [LENGTH];

            temp = temp[uchar(name[i])].vertex;
        }
        
        if (temp[uchar(name[n - 1])].phone)
            delete [] temp[uchar(name[n - 1])].phone;

        temp[uchar(name[n - 1])].phone = new char [strlen(phone) + 1];
        strcpy(temp[uchar(name[n - 1])].phone, phone);
    }

    char const * find(char const * name) {
        size_t n = strlen(name);

        if (!n)
            return head[0].phone;

        Vertex * temp = head;
                
        for (size_t i{0}; i < n - 1; ++i) {
            if (!temp[uchar(name[i])].vertex)
                return nullptr;

            temp = temp[uchar(name[i])].vertex;
        }

        return temp[uchar(name[n - 1])].phone;
    }

    void remove(char const * name) {
        size_t n = strlen(name);
        
        if (!n) {
            delete [] head[0].phone;
            head[0].phone = nullptr;
            return;
        }

        Vertex * temp = head;
                
        for (size_t i{0}; i < n - 1; ++i) {
            if (!temp[uchar(name[i])].vertex)
                return;

            temp = temp[uchar(name[i])].vertex;
        }

        delete [] temp[uchar(name[n - 1])].phone;
        temp[uchar(name[n - 1])].phone = nullptr;
    }
};
