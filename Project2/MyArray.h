/*ДЗ 03 Марта:
Реализовать паттерн "Стратегия" на основе примера, приведенного в презентации.Применить две стратегии сортировки - по возрастанию и по убыванию*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortStrategy abstract
{
public:
    virtual void Sort(vector<string>& v) abstract;
};

class SortUp : public SortStrategy
{
public:
    void Sort(vector<string>& v) override
    {
        sort(v.begin(), v.end());
    }
};

class SortDown : public SortStrategy
{
public:
    void Sort(vector<string>& v) override
    {
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }
};



class SortedArray
{
    vector<string> vector;
    SortStrategy* sortstrategy;

public:
    void SetSortStrategy(SortStrategy* sortstrategy)
    {
        this->sortstrategy = sortstrategy;
    }
    void Add(string name)
    {
        vector.push_back(name);
    }
    void Sort()
    {
        sortstrategy->Sort(vector);

        for (string name : vector)
        {
            cout << " " + name << endl;
        }
        cout << endl;
    }
};

int main()
{
    SortedArray ar;

    ar.Add("Strategy");
    ar.Add("Observer");
    ar.Add("Iterator");
    ar.Add("Mediator");

    SortUp shell;
    ar.SetSortStrategy(&shell);
    ar.Sort();

    ar.Add("Memento");
    ar.Add("Interpreter");

    SortDown stl;
    ar.SetSortStrategy(&stl);
    ar.Sort();
}



