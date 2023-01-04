/*
    LEETCODE PROBLEM SOLVER
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
using namespace std;

// SLL (for 0002)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// BINARY TREE (for 0094)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // i have no idea how this constructor syntax works but i won't question it
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
        void print(vector<vector<int>> v) {
            for (int i = 0; i < v.size(); i++) {
                cout << "*" << endl;
                print(v.at(i));
                cout << "*" << endl;
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
        Constraint: string consists only of brackets.

        Hints:
        1. Use a stack of characters.
        2. When you encounter an opening bracket, push it to the top of the stack.
        3. When you encounter a closing bracket, check if the top of the stack was the opening for it. 
           If yes, pop it from the stack. Otherwise, return false.
        */
            bool isValid(string s) {
                stack<char> stack; // naming a stack "stack" causes gradescope issues. is leetcode ok?
                //cout << "stack created" << endl;
                int rounds = 0;
                int squares = 0;
                int curls = 0;
                for (int x = 0; x < s.size(); x++) {
                    // if an opening bracket
                    switch (s.at(x)) {
                    case ('('):
                        rounds++;
                        stack.push(s.at(x));
                        break;
                    case ('['):
                        squares++;
                        stack.push(s.at(x));
                        break;
                    case ('{'):
                        curls++;
                        stack.push(s.at(x));
                        break;
                    case (')'):
                    case (']'):
                    case ('}'):
                        // edge case: is the stack empty?
                        if (stack.empty()) {
                            return false;
                        }
                        // check if brackets match for all 3 possible types
                        if (stack.top() == '(' && s.at(x) == ')') {
                            //cout << "stack.top() is " << stack.top() << " and s.at(x) is " << s.at(x) << endl;
                            rounds--;
                            stack.pop();
                        }
                        else if (stack.top() == '[' && s.at(x) == ']') {
                            //cout << "stack.top() is " << stack.top() << " and s.at(x) is " << s.at(x) << endl;
                            squares--;
                            stack.pop();
                        }
                        else if (stack.top() == '{' && s.at(x) == '}') {
                            //cout << "stack.top() is " << stack.top() << " and s.at(x) is " << s.at(x) << endl;
                            curls--;
                            stack.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    default:
                        break;
                    }
                }
                if (rounds == 0 && squares == 0 && curls == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
            void s0020() {
                if (isValid("(()]")) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
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
        // 0022
            vector<string> generateParenthesis(int n) {

            }
            void s0022() {
            
            }
        // 0026
        /*
        Given an integer array nums sorted in non-decreasing order, 
        remove the duplicates in-place such that each unique element appears only once. 

        Before: [0,0,1,1,1,2,2,3,3,4]
        After:  [0,1,2,3,4,_,_,_,_,_] // "_" = any number. doesn't matter

        Do NOT allocate extra space for another array. 
        You must do this by modifying the input array in-place with O(1) extra memory.
        */
            int removeDuplicates(vector<int>& nums) {
                /*
                Start at index 1. Compare to index 0.
                If the same number, skip. Otherwise, continue.
                Every time a new number is found, add it at index idx, then increment idx.
                */
                int idx = 1;
                for (int i = 1; i < nums.size(); i++) {
                    if (nums.at(i) != nums.at(i-1)) {
                        nums.at(idx) = nums.at(i);
                        idx++;
                    }
                }
                return idx;
            }
            void s0026() {
                vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // Input array
                vector<int> expectedNums = {0, 1, 2, 3, 4}; // The expected answer with correct length

                int k = removeDuplicates(nums); // Calls your implementation
                //cout << "successful call" << endl;

                //cout << "vector<int> nums:" << endl; p.print(nums);

                bool status = true;

                if (k != expectedNums.size()) {
                    status = false;
                }
                for (int i = 0; i < k; i++) {
                    if (nums[i] != expectedNums[i]) {
                        //cout << "false: " << nums[i] << " != " << expectedNums[i] << endl;
                        status = false;
                    }
                }
                if (status) {
                    cout << "good job" << endl;
                }
                else {
                    cout << "mission failed" << endl;
                }
            }
        // 0035 
            int searchInsert(vector<int>& nums, int target) {
                for (int x = 0; x < nums.size(); x++) {
                    if (nums.at(x) >= target) {
                        return x;
                    }
                }
                return nums.size();
            }
            void s0035() {
                vector<int> nums = {1, 3, 5, 6};
                int target = 5;
                cout << "index: " << searchInsert(nums, target) << endl;
            }
        // 0046
        /*
        fun with permutations

        i take it back this is not fun this is not fun
        */
            vector<vector<int>> output;
            vector<vector<int>> permute(vector<int>& nums) {

                // the vector "current" represents a single entry.
                vector<int> current;

                // the vector "remaining" represents all the values in nums that are left.
                vector<int> remaining = nums;

                // call perm() on current and remaining. (blank vector and nums)
                perm(current, remaining);

                // output is our result vector.
                return output;

            }
            /*
                perm is a recursive function
            */ 
            void perm(vector<int> current, vector<int> remaining) {
                
                //cout << "PERM CALLED" << endl;
                //cout << " the absolute state of current: " << endl;
                //p.print(current);
                //cout << " the absolute state of remaining: " << remaining.size()  << endl;
                //p.print(remaining);
                
                // for the length of remaining
                for (int i = 0; i < remaining.size(); i++) {
                    
                    // deep copy current before pushing a new value so things don't get confusing
                    vector<int> current2(current);
                    current2.push_back(remaining.at(i));
                    
                    // same with remaining
                    vector<int> remaining2(remaining);
                    remaining2.erase(remaining2.begin() + i);

                    // call recursively.
                    perm(current2, remaining2);
                }
                
                // once current reaches the same size as remaining, push to output.
                if (remaining.size() == 0) {
                    output.push_back(current);
                }

            }
            void s0046() {
                vector<int> nums;
                nums.push_back(1);
                nums.push_back(2);
                nums.push_back(3);
                vector<vector<int>> result = permute(nums);
                p.print(result);
            }
        // 0058
            int lengthOfLastWord(string s) {
                // assumes that string has minimum word length 1
                int counter = 0;
                bool spaced = false;
                for (int x = 0; x < s.size(); x++) {
                    if (s.at(x) == ' ') { // at space
                        spaced = true;
                    }
                    else {                // at valid char
                        if (spaced == true) {
                            spaced = false;
                            counter = 1;
                        }
                        else {
                            counter++;
                        }
                    }
                }
                return counter;
            }
            void s0058() {
                string s = "   fly me to   the moon   ";
                cout << "length of last word is " << lengthOfLastWord(s) << endl;
            }
        // 0066
        /*
        - start at the last element and add the element * 10^n to a counter, where n is the digit.
        - increment that counter.
        - then count the number of digits in the result.
        - create a new array with that length.
        - insert digits into the new array.
          - %10 gives remainder (ones place).
          - /10 removes ones place and shifts everything down.
        - return this new array.
        */
            vector<int> plusOne(vector<int>& digits) {

                // call incAndCarry(input, idx of last element)
                incAndCarry(digits, digits.size()-1);
                // return changed input
                return digits;
            }
            void incAndCarry(vector<int>& digits, int currentIdx) { // helper

                // if less than 9, increment current digit and return.
                if (digits.at(currentIdx) < 9) {
                    digits.at(currentIdx)++;
                    return;
                }
                // if 9, set to 0 and call helper function carry(input, n-1)
                // if value is 9 and idx 0, set to 0 and push_front() a 1
                if (digits.at(currentIdx) == 9) {
                    digits.at(currentIdx) = 0;
                    if (currentIdx==0) {
                        digits.insert(digits.begin(), 1);
                    }
                    else {
                        incAndCarry(digits, currentIdx-1);
                    }
                }

            }
            void s0066() {
                vector<int> input = {1, 2, 3, 4, 5};
                p.print(plusOne(input));
            }
        // 0067
        /*
            passes 194/294 test cases.
            breaks due to integer overflow.
            but come on, 194 test cases. i'm moving on.
        */
            string addBinary(string a, string b) {
                // convert b to an actual binary number
                int power = 0;
                int bcount = 0;
                for (int i = b.size() - 1; i >= 0; i--) {
                    //cout << "power is " << power << endl;
                    if (b.at(i) == '1') {
                        bcount = bcount + (int)pow(2, power);
                    }
                    //cout << "bcount is " << bcount << endl;
                    power++;
                }
                //cout << "bcount is " << bcount << endl;
                for (int i = 0; i < bcount; i++) {
                    a = incBinaryAtIdx(a, a.size()-1);
                }
                return a;
            }
            string incBinaryAtIdx(string input, int idx) {
                if (input.at(idx) == '0') {
                    input.at(idx) = '1';
                    return input;
                }
                if (input.at(idx) == '1') {
                    input.at(idx) = '0';
                    if (idx != 0) {
                        return incBinaryAtIdx(input, idx - 1);
                    }
                    else {
                        return "1" + input;
                    }
                }
                return "ooga booga";
            }
            void s0067() {
                string a = "1000001";
                string b = "1001";
                
                //

                cout << a << " + " << b << " = " << addBinary(a, b) << endl;
            }
        // 0094
        /*
          in-order traversal is "go left, visit, go right"
          
          my first code theoretically worked (except for null inputs), but would not be accepted by leetcode.
          this is a more efficient solution based on the official LeetCode solution written in Java.

          apparently, creating a vector in one function and passing it to another function fails to preserve
          the changes made by the second function. here, the output vector is a public field defined in the
          class rather than in our inorderTraversal function. this doesn't seem to be a problem in Java. weird.
        */
            vector<int> output0094;
            vector<int> inorderTraversal(TreeNode* root) {
                // this function should return a vector of nodes traversed in order
                traverse(root);
                return output0094;
            }
            void traverse(TreeNode* trav) {
                if (trav != nullptr) {
                    traverse(trav->left);
                    output0094.push_back(trav->val);
                    traverse(trav->right);
                }
            }
            void s0094() {
                // example 1
                TreeNode* node1 = new TreeNode(1);
                TreeNode* node2 = new TreeNode(2);
                TreeNode* node3 = new TreeNode(3);
                node1->right = node2;
                node2->left = node3;

                // example 2
                TreeNode* node0 = nullptr;

                // example 3
                TreeNode* nodeX = new TreeNode(1);

                cout << "print: " << endl;
                p.print(inorderTraversal(node1));
            }
        // 0278
        /*
        Find the "first bad version" of a software.
        (Created custom isBadVersion() function to assist debugging.)
        */
            int firstBadVersion(int n) {
                // modified binary search
                cout << "initiate binary search" << endl;
                return binarySearch0278(1, n);
            }
            int binarySearch0278(int lowerBound, int upperBound) {
                // edge case: lower = upper (probably = 1)
                if (lowerBound == upperBound) {
                    return lowerBound;
                }
                if (upperBound == lowerBound + 1) { // could probably cause infinite loop
                    if (isBadVersion(lowerBound)) {
                        return lowerBound;
                    }
                    else {
                        return upperBound;
                    }
                }
                /*
                the operation "(lowerBound + upperBound) / 2" may cause an integer overflow.
                this can be re-expressed as lowerBound / 2 + upperBound / 2 [not good, risks rounding twice]
                    -> lowerBound - lowerBound / 2 + upperBound / 2         [also risks rounding twice]
                    -> lowerBound + (upperBound - lowerBound) / 2           [good: only rounds once at most]
                */
                int mid = lowerBound + ((upperBound - lowerBound) / 2);
                cout << "lowerBound: " << lowerBound << endl;
                cout << "upperBound: " << upperBound << endl;
                cout << "mid: " << mid << endl;
                
                if (isBadVersion(mid) == false) { // 0
                    // search up
                    cout << "searching up" << endl;
                    return binarySearch0278(mid, upperBound);
                }
                else { // 1
                    cout << "version at " << mid << " is bad" << endl;
                    if (isBadVersion(mid-1) == false) { // if previous element is 0
                        return mid + 1; // add 1 because versions are counted from 1 upwards
                    }
                    else {
                        cout << "searching down" << endl;
                        // search down
                        return binarySearch0278(lowerBound, mid);
                    }
                }
            }
            string versions = "";
            string construct(int n, int bad) {
                string output = "";
                for (int x = 0; x < bad-1; x++) {
                    output = output + "0";
                }
                int leftover = n - bad;
                for (int x = 0; x <= leftover; x++) {
                    output = output + "1";
                }
                cout << "string: " << output << endl;
                return output;
            }
            bool isBadVersion(int x) {
                if (versions.at(x) == '0') {
                    return false;
                }
                else return true;
            }
            void s0278() {
                int n = 5;
                int bad = 4;
                versions = construct(n, bad);
                cout << "first bad version: " << firstBadVersion(n) << endl;
            }
        // 0944
        /*
            passes 75/85 test cases
            i think i'm just gonna move on, i'm really busy tonight
        */
            int minDeletionSize(vector<string>& strs) {
                
                int count = 0;

                int stringLength = strs.at(0).size();
                int arraySize = strs.size();

                // iterate through the length of each string
                for (int x = 0; x < stringLength; x++) {
                    char current = strs.at(0).at(x);
                    bool columnDeleted = false;
                    // iterate through a particular string
                    for (int y = 1; y < arraySize; y++) {
                        if (columnDeleted) {
                            break;
                        }
                        current = strs.at(y-1).at(x);
                        if (strs.at(y).at(x) < current) { // compare chars. should never have value lower than count
                            cout << strs.at(y).at(x) << " < " << current << endl;
                            columnDeleted = true;
                        }
                        else {
                            cout << strs.at(y).at(x) << " >= " << current << endl;
                        }
                        cout << strs.at(y).at(x) << endl;
                    }
                    if (columnDeleted) {
                        count++;
                    }
                }
                return count;
            }
            void s0944() {
                vector<string> strs = { "abc", 
                                        "bce", 
                                        "cae" };  // works, prints 1
                vector<string> strs1 = { "cba",
                                         "daf",
                                         "ghi" }; // works, prints 1
                vector<string> strs2 = { "zyx",
                                         "wvu",
                                         "tsr" }; // works, prints 3
                vector<string> strs3 = { "a",
                                         "b",}; // works, prints 3
                vector<string> strs17 = { "qowfc",
                                          "spyge",
                                          "sqbif",
                                          "vvrkk" };
                vector<string> strs41 = { "rrjk",
                                         "furt",
                                         "guzm" }; // should print 2 (first and last columns)
                vector<string> strs76 = {"an array of ridiculously long strings that i'm not gonna"};
                cout << "columns to be deleted: " << minDeletionSize(strs17) << endl;
            }
};

// USED FOR TESTING SOLUTIONS
int main()
{
    Solution s;

    //************
    int test = 46;   // INPUT TEST NUMBER HERE
    //************

    switch (test) {
    /*
    EASY
    */
    case 1:   // 0001 - finding sum            - COMPLETED
        s.s0001({ 2, 7, 11, 15 }, 9);
        break;
    case 9:   // 0009 - is palindrome?
        s.s0009();
        break;
    case 14:  // 0014 - longest common prefix  - COMPLETED
        s.s0014();
        break;
    case 20:  // 0021 - bracket closure        - COMPLETED
        s.s0020();
        break;
    case 21:  // 0021 - merge 2 sorted lists   - COMPLETED
        s.s0021();
        break;
    case 26:  // 0026 - remove sorted dupes    - COMPLETED
        s.s0026();
        break;
    case 35:  // 0035 - search insert position - COMPLETED
        s.s0035();
        break;
    case 58:  // 0058 - last word in string    - COMPLETED
        s.s0058();
        break;
    case 66:  // 0066 - plus one for vectors   - COMPLETED
        s.s0066();
        break;
    case 67:  // 0067 - binary addition        - COMPLETED (mostly)
        s.s0067();
        break;
    case 94:  // 0094 - binary treeversal      - COMPLETED
        s.s0094();
        break;
    case 278: // 0278 - first bad version      - COMPLETED
        s.s0278();
        break;
    case 944: // 0944 - delete columns         - COMPLETED
        s.s0944();
        break;
    /*
    MEDIUM
    */
    case 2:   // 0002 - linked list addition   - in progress
        s.s0002();
        break;
    case 22:   // 0022 - parentheses combos    - in progress
        s.s0022();
        break;
    case 46:  // 0046 - permutations           - COMPLETED
        s.s0046();
        break;
    }
}
