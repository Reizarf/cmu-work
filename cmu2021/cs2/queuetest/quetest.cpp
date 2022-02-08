#include <ctime>
#include <queue>
#include <iostream>
#include <string>

class Data
{
    
public:
    Data(int pos, time_t tm)
    {
        position = pos;
        time = tm;
    }
    
    int getPosition()
    {
        return position;
    }
    
    time_t getTime()
    {
        return time;
    }
    
    std::string toString()
    {
        return "Position: " + std::to_string(position) + " Time: " + asctime(localtime(&time));
    }
    
private:
    int position;
    time_t time;
    
};

int main()
{
    // create queue
    std::queue<Data> dq;
    
    // create time structure
    time_t timer;
    
    // initialise position number
    int qPosition = 0;
    
    // create and test a Data object
    Data dat1 = Data( qPosition, time(&timer));
    std::cout << dat1.getPosition() << ' ' << dat1.getTime() << std::endl;
    
    // test data queue
    dq.push(dat1);
    
    for(int i = 0; i < 5; i++)
        dq.push( Data( ++qPosition, timer + i*1000 ) );
    
    std::cout << dq.size() << " people in the queue." << std::endl;
    
    //list all people in the queue (dequeue would be better)
    int limit = (int)dq.size();
    for ( int i = 0; i < limit; i++ )
    {
        std::cout << dq.front().toString();
        dq.push(dq.front());
        dq.pop();
    }
}