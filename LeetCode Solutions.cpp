/*
    LEETCODE PROBLEM SOLVER
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

// CUSTOM SLL (for 0002)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// PRINTER (used by SOLUTION)
class Printer {
    public:
        // PRINT FUNCTIONS
        void print(vector<int> v) {
            for (int x = 0; x < v.size(); x++) {
                cout << v.at(x) << endl;
            }
        }
        void print(list<int> l) {
            for (int x : l) {
                cout << x << endl;
            }
        };
        void print(ListNode* l) {
            while (l != nullptr) {
                cout << l->val << endl;
                l = l->next;
            }
        }
};

// LINKED LIST CREATOR
class SLL {
    public:
        ListNode* createList(vector<int> input) {
            ListNode* node;
            ListNode* head = new ListNode(input.at(0));
            ListNode* prev = head;
            for (int i = 1; i < input.size(); i++) {
                node = new ListNode(input.at(i));
                prev->next = node;
                prev = node;
            }
            return head;
        }
};

// SOLUTION (used by main)
class Solution {
    public:
        // PRINTER object
        Printer p;
        SLL s;
        // 0001
       /* 
        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.
        */
            vector<int> twoSum(vector<int>& nums, int target) {
                for (int x = 0; x < nums.size() - 1; x++) {
                    for (int y = x + 1; y < nums.size(); y++) {
                        if (nums.at(x) + nums.at(y) == target) {
                            return { x, y };
                        }
                    }
                }
                return {};
            }
            void s0001(vector<int> input, int target) {
                p.print(twoSum(input, target));
            };
        // 0002
        /*
        You are given two non-empty linked lists representing two non-negative integers.
        The digits are stored in reverse order, and each of their nodes contains a single digit.
        Add the two numbers and return the sum as a linked list.

        You may assume the two numbers do not contain any leading zero, except the number 0 itself.
        */
            ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                // first take l1 and convert to an int value
                double l1int = convert(l1);
                //cout << "CONVERTED: " << l1int << endl;
                double l2int = convert(l2);
                //cout << "CONVERTED: " << l2int << endl;
                
                int sum = l1int + l2int;
                //cout << "SUM: " << sum << endl;
                // we now have our integer value we want to convert to a linked list.
                // first find the number of digits.
                // - this can be done by continually dividing by 10.
                // - a more efficient method is to take log10(sum) + 1.
                int digits = int(log10(sum) + 1);
                // then create a vector with length = number of digits
                vector<int> vec;
                for (int i = 0; i < digits; i++) {
                    vec.push_back(sum % 10);
                    sum /= 10;
                }
                //p.print(vec);
                // then create a ListNode* for each digit and insert the respective value.
                ListNode* node;
                ListNode* head = new ListNode(vec.at(0));
                ListNode* prev = head;
                for (int i = 1; i < digits; i++) {
                    node = new ListNode(vec.at(i));
                    prev->next = node;
                    prev = node;
                }
                //cout << "---" << endl;
                //p.print(head);
                //cout << "---" << endl;
                // then reverse the list. this part is easy.
                // did we do it already on accident?
                return head;
            }
                double convert(ListNode* l) {
                double count = 0;
                double exponent = 1;
                ListNode* head = l;
                while (head != nullptr) {
                    count = count + (head->val * exponent);
                    exponent = exponent * 10;
                    head = head->next;
                }
                return count;
            }
            void s0002() {
                ListNode* l1A = new ListNode(2);
                ListNode* l1B = new ListNode(4);
                ListNode* l1C = new ListNode(3);
                l1A->next = l1B;
                l1B->next = l1C;

                ListNode* l2A = new ListNode(5);
                ListNode* l2B = new ListNode(6);
                ListNode* l2C = new ListNode(4);
                l2A->next = l2B;
                l2B->next = l2C;
                p.print(addTwoNumbers(l1A, l2A));
                //
            };
        // 0009
            bool isPalindrome(int x) {
                if (x < 0) {
                    return false; // negative numbers will never be palindromes. take a guess why
                }
                return true;
            }
            void s0009() {

            };
        // 0014
            string longestCommonPrefix(vector<string>& strs) {
                string output = "";
                // first find whichever string is the shortest
                int smallest = strs.at(0).length();
                for (int x = 1; x < strs.size(); x++) {
                    if (strs.at(x).length() < smallest) {
                        smallest = strs.at(x).length();
                    }
                }
                //cout << "smallest is " << smallest << endl;
                // now iterate through smallest
                for (int x = 0; x < smallest; x++) {
                    char letter = strs[0].at(x);
                    bool match = true;
                    // compare letters of all strings at given index
                    for (int y = 1; y < strs.size(); y++) {
                        if (strs[y].at(x) != letter) {
                            match = false;
                        }
                    }
                    if (match == true) {
                        output = output + letter; // shouldn't matter which element we pick
                    }
                    else {
                        break;
                    }
                }
                return output;
            }
            void s0014() {
                vector<string> input = { "flower", "flow", "flight" };
                cout << "longest common prefix: \"" << longestCommonPrefix(input) << "\"" << endl;
            }
        // 0020
        /*
        Given a string s containing only round/curly/square brackets, determine if the input string is valid.
        It's valid if the brackets open and close in a manner that makes intuitive sense.
            valid ex: "()[]{}", "({})", "()[()]"
            invalid ex: "(}", "[(])", "{"
        */
            bool isValid(string s) {

            }
            void s0020() {

            }
        // 0021
            ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                /*
                edge cases:
                - if list1 or list2 is nullptr, return whichever the other one is.
                */
                if (list1 == nullptr) {
                    return list2;
                }
                if (list2 == nullptr) {
                    return list1;
                }

                /*
                first we need to decide which should be the head of our new linked list.
                */
                ListNode* head;
                if (list1->val <= list2->val) {
                    head = new ListNode(list1->val);
                    list1 = list1->next;
                    //cout << "new head created: list1 head erased" << endl;

                }
                else {
                    head = new ListNode(list2->val);
                    list2 = list2->next;
                    //cout << "new head created: list2 head erased" << endl;

                }
                ListNode* prev = head;
                /*
                repeat until either list1 or list2 is null:
                - compare list1 and list2.
                - take the smaller value and put it at the front of a new linked list.
                - then erase the value where it was originally (head = head->next).
                at the end of this loop, either list1 or list2 is left.
                just append it to the end of our newly created linked list.
                */
                ListNode* newNode;
                while (list1 != nullptr && list2 != nullptr) {
                    if (list1->val < list2->val) {
                        newNode = new ListNode(list1->val);
                        prev->next = newNode;
                        prev = newNode;
                        list1 = list1->next;
                        //cout << "list1 head erased" << endl;
                    }
                    else {
                        newNode = new ListNode(list2->val);
                        prev->next = newNode;
                        prev = newNode;
                        list2 = list2->next;
                        //cout << "list2 head erased" << endl;
                    }
                }
                /*
                now, either list1 or list2 will be left.
                figure out which one it is and append it to prev. (prev->next)
                */
                if (list1 != nullptr) {
                    prev->next = list1;
                }
                if (list2 != nullptr) {
                    prev->next = list2;
                }
                return head;
            }
            void s0021() {
                ListNode* list1 = s.createList({ 1, 2, 4 });
                ListNode* list2 = s.createList({ 1, 3, 4 });
                p.print(mergeTwoLists(list1, list2));
            }
};

// USED FOR TESTING SOLUTIONS
int main()
{
    Solution s;

    //************
    int test = 21;   // INPUT TEST NUMBER HERE
    //************

    switch (test) {
    /*
    EASY
    */
    case 1:  // 0001 - finding sum            - COMPLETED
        s.s0001({ 2, 7, 11, 15 }, 9);
        break;
    case 9:  // 0009 - is palindrome?
        s.s0009();
        break;
    case 14: // 0014 - longest common prefix  - COMPLETED
        s.s0014();
        break;
    case 20: // 0021 - bracket closure
        s.s0020();
        break;
    case 21: // 0021 - merge 2 sorted lists   - COMPLETED
        s.s0021();
        break;
    /*
    MEDIUM
    */
    case 2:  // 0002 - linked list addition   - in progress
        s.s0002();
        break;
    }
}
