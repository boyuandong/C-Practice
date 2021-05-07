/* There are Goods in store, buy in/ sell by boxes, weights varies defferent boxes.
Now record the total weight and buy in/sell out goods.
The Goods are stored as a linked list.
Each time buy in an item add it at the rear, sell an item delete it from the front.
First in first out rule.
*/
#include<iostream>
using namespace std;
class Goods
{
    public:
        Goods(int w)
        {
            weight = w;
            total_weight += w;          // add the weight to total whenever there is one more good bought in
        }
        ~Goods()
        {
            total_weight -= weight;     // delete the weight from the total when sell this good.
        }
        int Weight() {return  weight;}
        static int TotalWeight() {return total_weight;}     // This is a static function for this class
        Goods * next;
    
    private:
        int weight;
        static int total_weight;                // This is a private static instance for this class
};

int Goods::total_weight = 0;         // initial the static value to zero
void purchase(Goods *&f, Goods *& r, int w)     // buy in goods, insert at the end of linked list
{
    Goods * p = new Goods(w);
    p->next = NULL;
    if(f==NULL)     // list is empty
    {
        f = r = p;      // there is only one good
    }   
    else    // Otherwise, insert new Good to the rear of list
    {
        r->next = p;
        r = r->next;
    }
}
void sale(Goods *& f, Goods *& r)       // sell the Goods, delete item from the front of list
{
    if(f == NULL)    // list is empty
    {
        cout<<"No any Goods!\n";
        return;
    }
    Goods *q = f;
    f = f->next;
    delete q;
    q = NULL;
    cout<<"saled.\n";
}
int main()
{
    Goods *front = NULL, *rear = NULL;
    int w;
    int choice;
    do{
        cout<<"Please choice:\n";
        cout<<"----------------------"<<endl;
        cout<<"Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n";
         cout<<"----------------------"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:     // purchase an item
            {
                cout<<"Input weight: ";
                cin>>w;
                purchase(front, rear, w);
                break;
            }
        case 2:     // sale an item    
            {
                sale(front, rear);
                break;
            }
        case 0:
            break;
        }
        cout<<"Now total weight is: "<<Goods::TotalWeight()<<endl;
    }while(choice);
}