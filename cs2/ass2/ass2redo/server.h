// #include "queue.h"
// #include "customer.h"
class Server
{
Server()
{
  string status = "free";
  int transactionTime = 0;
}
bool isFree()
{
  string status = "free";
  return (status == "free");
}
bool setBusy()
{
  string status = "busy";
  return (status == "busy");
}
void setFree()
{
  string status = "free";
}
void setTransactionTime(int t)
{
  int transactionTime = t;
}
void setTransactionTime(customerT customer)
{
  int time;
  time = customer.getTransactionTime();
  transactionTime = time;
}
void decreaseTransactionTime()
{
  transactionTime--;
}

private:
  int transactionTime = 0;
};