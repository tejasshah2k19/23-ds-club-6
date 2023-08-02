#include <iostream>
#define SIZE 52

using namespace std;

class Queue
{
    int q[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void insert(int num)
    {
        if (rear == SIZE - 1)
        {
            cout << "Queue is Full";
        }
        else
        {
            rear++;
            q[rear] = num;
            if (front == -1)
                front = 0;
        }
    }
    // remove function will return -1 if queue is empty
    // remove deleted element if data is present
    int remove()
    {
        int num;
        if (front == -1)
        {
            return -1; // when queue is empty
        }
        else
        {
            num = q[front]; // delete num
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            return num;
        }
    }
    void display()
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            cout << " " << q[i];
        }
    }
};

int main()
{

    Queue masterDec;  // 10  5  25 22 63 63 22 9
    Queue playerADec; // 10 25 63 22
    Queue playerBDec; // 5  22 63 9
    Queue battle;     // 10 5
    int tmp, i;
    int decSize = 8; // scan
    int playerAcard;
    int playerBcard;
    masterDec.insert(10);
    masterDec.insert(5);
    masterDec.insert(25);
    masterDec.insert(22);
    masterDec.insert(63);
    masterDec.insert(63);
    masterDec.insert(22);
    masterDec.insert(9);

    cout << "\nMASTER DEC \n";
    masterDec.display();

    for (i = 1; i <= decSize / 2; i++)
    {
        tmp = masterDec.remove();
        playerADec.insert(tmp);
        tmp = masterDec.remove();
        playerBDec.insert(tmp);
    }

    cout << "\nPlayerA DEC \n";
    playerADec.display();

    cout << "\nPlayerB DEC \n";
    playerBDec.display();

    int x = 1;

    for (x = 1; x <= 1000; x++)
    {

        cout << "\n Battle Round  : " << x;
        playerAcard = playerADec.remove();
        playerBcard = playerBDec.remove();

        if (playerAcard == -1)
        {
            // game over A
            cout << "\n PLAYER B IS THE WINNER FOR GAME";
            break;
        }
        else if (playerBcard == -1)
        {
            // game over B

            cout << "\n PLAYER A IS THE WINNER FOR GAME";
            break;
        }

        battle.insert(playerAcard);
        battle.insert(playerBcard);

        if (playerAcard > playerBcard)
        {
            // a is winner [10,5] battle.remove() 10 battle.remove() 5  battle.remove()
            // aDec -> 10 5
            cout << "\n Player A is Winner for This Round";
            while (1)
            {
                tmp = battle.remove();
                if (tmp == -1)
                {
                    break;
                }
                playerADec.insert(tmp);
            }
        }
        else if (playerBcard > playerAcard)
        {
            // b in winner

            cout << "\n Player B is Winner for This Round";
            while (1)
            {
                tmp = battle.remove();
                if (tmp == -1)
                {
                    break;
                }
                playerBDec.insert(tmp);
            }
        }
        else
        {
            // tie

            cout << "\n Tie In This Round";
        }
        cout << "\nAfter Round " << x;
        cout << "\nplayer A DEC\n";
        playerADec.display();

        cout << "\nplayer B DEC\n";
        playerBDec.display();
    }

    cout << "\n********  THE END ***************";
    return 0;
}
