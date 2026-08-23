#include "iostream"

using namespace std;

class Book
{
    string title;
    double price;
    int *stock=new int;
    public:
    Book()
    {
        title = "unknnown";
        price = 0.0;
        *stock = 30;
    }

    int trackrecord()
    {
      return *stock;
    }
    
    void update(string ti, double p, int st)
    {
        title = ti;
        price = p;
        *stock = st;
    }
    
    void purchaseBook(int books)
    {
        if(books > *stock)
        {
        cout << "Not enough stock" << endl;
        return; 
        } 
        if(*stock <= 5)
        {
            cout << "Low stock";
            return;   
        } 
        else
        {
            cout << "Books successfully purchased" << endl;
            *stock -= books;
        }

    }

    Book(string ti, double p, int st)
    {
        title = ti;
        price = p;
        *stock = st;

    }

    void applyDiscount(int books)
    {
        if(books >= 5)
        {
            price = price - (price*0.05);
            
        }
        else if(books >= 10)
        {
            price = price - (price*0.05);
        }
    }

    void stockValidation(int books)
    {
        if(books > *stock)
        {
            cout << "Not enough stock" << endl;
        }
    }
    
    Book(const Book& other) 
    {
        title = other.title;
        price = other.price;
        stock = other.stock;
    }

    ~Book() 
    {
        cout << title << " book is being destroyed" << endl;
    }

    void calculatePrice(int quantity) 
    {
        double basePrice = price;
        applyDiscount(quantity);
        if (quantity > 5) 
        {
            cout << "Applied discount new price: " << price << endl;
        }
        if (quantity > 10) 
        {
            cout << "Applied bulk discount new price: " << price << endl;
        }
    }

void displayBookDetails() 
{
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << " units" << endl;
    }

    string getTitle() { return title; }
    double getPrice() { return price; }
    int getStock() { return *stock; }

};

int main() 
{
    Book book1;
    book1.displayBookDetails();
    cout << "\n";
    book1.update("The Hobbit",2550,90);
    book1.displayBookDetails();
    cout << "\n";
    Book book2("Matilda",1480,70);
    book2.displayBookDetails();

    book1.purchaseBook(10);
    cout << "\n";
    book1.purchaseBook(50);
    cout << "\n";
    book1.applyDiscount(6);
    cout << "\n";
    Book book3=book2;
    book3.displayBookDetails();
    cout << "\n";

    book3.update("Lords Of Rings", 1200.99, 60);
    cout << endl << "Modified Details of Book 3 (After Modification):" << endl;
    book3.displayBookDetails();
    cout << endl << "Details of Book 2 (Unchanged):" << endl;
    book2.displayBookDetails();
    book2.calculatePrice(12);

    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();

    return 0;
}