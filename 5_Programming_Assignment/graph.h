#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex
{
    T label; // unique int for a vertex
    vector<T> adj_list;
    int indegree = 0;                           // Part 2: number of nodes pointing in
    int top_num;                            // Part 2: topological sorting number
    Vertex(T l) : label(l) { top_num = 0; } //Part 1
                                            // You may include default constructor optionally.
    Vertex()
    {
    }
};


// optional, but probably helpful
// template <class T>
// ostream& operator<<(ostream &o, Vertex<T> v){};

// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor
// Refer the instructions PDF last section for more information

template <class T>
class VertexCompare
{
public:
    bool operator()(Vertex<T> v1, Vertex<T> v2)
    {
        if(v1.top_num >= v2.top_num) return true;
        return false;
    }
};

template <class T>
class Graph
{
private:
    //c++ stl hash table

    unordered_map<T, Vertex<T>> node_set;
    //Use other data fields if needed
public:
    Graph(){};  //No modification needed to default constructor. Can be used optionally if needed.
    ~Graph(){}; //No modification needed to destructor. Can be used optionally if needed.

    // build a graph - refer the instructions PDF for more information.
    void buildGraph(istream &input) 
    {
        node_set.clear();
        string labelInput;
        
        while(getline(input, labelInput))
        {
            stringstream strStream(labelInput);
            T currLabel;
            strStream >> currLabel;
            T rootLabel = currLabel;
            Vertex<T> node(rootLabel);
            
            while(strStream >> currLabel)
            {
                node.adj_list.push_back(currLabel);
            }
            node_set.insert(make_pair(rootLabel, node));
        }
    }

    // display the graph into o - refer the instructions PDF for more information.
    void displayGraph(ostream &o) 
    {
        typename unordered_map<T, Vertex<T>>::iterator it = node_set.begin();
        while(it != node_set.end())
        {
            o << it->first << " :";
            for(T element : it->second.adj_list)
            {
                o << " " << element;
            }
            o << "\n";
            it++;
        }
    }

    //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
    Vertex<T> at(T label) //Maybe change implementation
    {
        return node_set.at(label);
        // typename unordered_map<T, Vertex<T>>::iterator it = node_set.begin();
        // while(it != node_set.end())
        // {
        //     if(it->first == label)
        //     {
        //         return it->second;
        //     }
        //     it++;
        // }
        // throw runtime_error("Vertex not present");
    }

    //return the graph size (number of verticies)
    int size() 
    {
        return node_set.size();
    }

    // topological sort
    // return true if successful, false on failure (cycle)
    bool topological_sort() 
    {
        queue<Vertex<T>*> q;
        int counter = 0;
        typename unordered_map<T, Vertex<T>>::iterator it = node_set.begin();
        while(it != node_set.end())
        {
            if(at(it->first).indegree == 0)
            {
                q.push(&it->second);
            }
            it++;
        }
        while(!q.empty())
        {
            Vertex<T>* v = q.front();
            q.pop();
            v->top_num = ++counter;
            for(T label : v->adj_list)
            {
                Vertex<T>* vAt = &node_set[label];
                if(--vAt->indegree == 0)
                {
                    q.push(vAt);
                }
            }
        }

        if(counter != node_set.size()) return false;
        return true;
    } // Part 2

    // find indegree
    void compute_indegree()
    {
        typename unordered_map<T, Vertex<T>>::iterator it = node_set.begin();
        while(it != node_set.end())
        {
            for(T elementLabel : it->second.adj_list)
            {
                node_set[elementLabel].indegree++;
            }
            it++;
        }
    } // Part 2

    // print topological sort into o
    //  if addNewline is true insert newline into stream
    void print_top_sort(ostream &o, bool addNewline = true)
    {
        if(node_set.size() != 0)
        {
            priority_queue<Vertex<T>, vector<Vertex<T>>, VertexCompare<T>> pQ; 
            typename unordered_map<T, Vertex<T>>::iterator it = node_set.begin();
            while(it != node_set.end())
            {
                pQ.push(it->second);
                it++;
            }
            while(!pQ.empty())
            {
                o << pQ.top().label << " ";
                pQ.pop();
            }
        }
        if (addNewline)
            {
                o << '\n';
            }
    } // Part 2
};

#endif
