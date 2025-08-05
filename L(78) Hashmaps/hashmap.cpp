#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Declare a hashmap (unordered_map) with string keys and int values
    unordered_map<string, int> scores;

    // 1️⃣ Insert elements into the map
    scores["Alice"] = 90;       // Insert using bracket notation
    scores.insert({"Bob", 85}); // Insert using insert() method

    // 2️⃣ Access elements
    cout << "Alice's score: " << scores["Alice"] << endl; // Access using key
    cout << "Bob's score: " << scores.at("Bob") << endl;  // Safer access, throws exception if key not found

    // 3️⃣ Update an existing element
    scores["Alice"] = 95; // Overwrites Alice's previous score

    // 4️⃣ Check if a key exists
    if (scores.find("Charlie") == scores.end())
    {
        cout << "Charlie is not in the map." << endl;
    }

    if (scores.find("Charlie") == scores.end())
    {
        cout << "Charlie is not in the map." << endl;
    }

    // 5️⃣ Delete an element
    scores.erase("Bob"); // Removes Bob from the map

    // 6️⃣ Iterate over all elements
    for (auto &pair : scores)
    {
        cout << pair.first << ": " << pair.second << endl; // key: value
    }

    // 7️⃣ Size of the map
    cout << "Total number of entries: " << scores.size() << endl;

    // 8️⃣ Clear the entire map
    scores.clear(); // Removes all elements

    // Check if map is empty
    if (scores.empty())
    {
        cout << "Map is now empty." << endl;
    }

    return 0;
}
