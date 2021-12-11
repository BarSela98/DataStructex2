#include <iostream>
#include <string>
#include <sstream>
#include <bits.h>
#include "heapsManager.h"
using namespace std;
#define SIZE 100

void main() {
    int counter_wr = 0;
    heapsManager *heaps = nullptr;
    int counter = -1, numOfActions,priority,pairsCounter=0;
    bool goodInput = true;
    string line,word,temp;
    cin >> numOfActions;
    if (numOfActions < 1)
        goodInput = false;
    getchar();//takes the enter *****CHANGE!
    do
    {

        getline(cin, line);
        ++counter;

        istringstream ss(line);
        if (!(ss >> word))//line was "\n"
            goodInput = false;
        if (word != "e" && counter == 0 || word == "e" && counter != 0)//first line isnt "e" or another e
            goodInput = false;

        if (word == "a")
        {
            if (ss >> word)
                goodInput = false;
            if (pairsCounter == 0)
                goodInput = false;
            if (goodInput)
            {
                cout << heaps->Max();
            }

        }
        else if (word == "b")
        {

            if (pairsCounter == 0)
                goodInput = false;
            if (ss >> word)
                goodInput = false;
            if (goodInput)
            {
                cout << heaps->DeleteMax();
                pairsCounter--;
            }

        }
        else if (word == "c")
        {
            if (ss >> word)
                goodInput = false;
            if (pairsCounter == 0)
                goodInput = false;
            if (goodInput)
            {
                cout << heaps->Min();
            }
        }
        else if (word == "d")
        {
            if (pairsCounter == 0)
                goodInput = false;
            if (ss >> word)
                goodInput = false;
            if (goodInput)
            {
                cout << heaps->DeleteMin();
                pairsCounter -- ;
            }
        }
        else if (word == "e")
        {
            if (ss >> word)
                goodInput = false;
            if (goodInput)
            {
                heaps = new heapsManager(SIZE);
            }
        }
        else if (word == "f")
        {
           
            if (!(ss >> word))
                goodInput = false;
            if (goodInput)
            {
                priority = stoi(word);
                if (!(ss >> word))
                    goodInput = false;
                
                while (ss >> temp)
                {
                    word+=" ";
                    word += temp;
                }
                    
                    
                heaps->Insert(priority, word);
                pairsCounter++;
            }
        }
        else if (word == "g")
        {
            if (pairsCounter == 0)
                goodInput = false;
            if (ss >> word)
                goodInput = false;
            if (goodInput)
            {
                cout << heaps->Median();
            }
        }
        else//not a valid command
         goodInput = false;

        if (!goodInput)
        {
            if (counter_wr == 0)
            {
                cout << "wrong input" << endl;
                counter_wr++;
            }
            else if (counter == numOfActions)
            {
            }
        }
    } while (line.size() != 0);

    if (counter > numOfActions)
        goodInput = false;
    if (heaps != nullptr)
        delete heaps;
 
}
