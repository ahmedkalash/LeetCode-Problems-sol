//
// Created by ahmed on 07/03/23.
//

#ifndef UNTITLED_TRIE_H
#define UNTITLED_TRIE_H
#include <bits/stdc++.h>
#include "strstream"

using namespace std;
namespace k
{
    template<typename t>
    class vector {

    };

}
#define vc vector
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pci pair<char, int>
#define pcl pair<char, long long>
#define psi pair<string, int>
#define psl pair<string, long long>
#define el  endl
#define ull unsigned long long
#define ll long long

#define pn cout << "no" << endl
#define Pn cout << "No" << endl
#define PN cout << "NO" << endl
#define py cout << "yes" << endl
#define Py cout << "Yes" << endl
#define PY cout << "YES" << endl
#define fi first
#define se second

struct Node{
    bool is_word=0;
    int ctr=0;
    Node* next[26]{};
    ~Node(){
        for (auto &ptr:next) {
            delete ptr;
            ptr= nullptr;
        }
    }
};

struct Trie
{
    Node head;
    void insert(const string& str)
    {
        Node* current = &head;
        for (auto ch:str) {
            ch -='a';
            if(!current->next[ch]) {  current->next[ch] = new Node(); }
            current = current->next[ch];
            current->ctr++;
        }
        current->is_word =1;
    }

    bool has(const string& str)
    {
        Node* current = &head;
        for (auto ch:str) {
            ch -='a';
            if(!current->next[ch]) {  return 0;}
            current = current->next[ch];
        }
        return current->is_word ;
    }
    int count(const string& str)
    {
        Node* current = &head;
        for (auto ch:str) {
            ch-='a';
            if(!current->next[ch]){ return 0;}
            current = current->next[ch];
        }
        return current->ctr;
    }


    ~Trie(){}


};


struct Node {
    bool is_word = false;
    int cnt = 0;
    Node *next[26]{};


    void insert(const string& s) {
        Node *current = this;
        for (char c : s) {
            int i = c - 'a';
            if (not current->next[i]) { current->next[i] = new Node; }
            current = current->next[i];
            ++current->cnt;
        }
        current->is_word = true;
    }


    bool contains(const string &s) {
        Node *current = this;
        for (char c : s) {
            int i = c - 'a';
            if (not current->next[i])
                return false;
            current = current->next[i];
        }
        return current->is_word;
    }
    int count(const string &s) {
        Node *current = this;
        for (char c : s) {
            int i = c - 'a';
            if (not current->next[i])
                return 0;
            current = current->next[i];
        }
        return current->cnt;
    }
};
#endif //UNTITLED_TRIE_H
