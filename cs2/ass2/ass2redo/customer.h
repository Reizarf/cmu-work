
class customerT
{
public:
  

  void customer(int custNum = 0, int arrvTime = 0,int wTime = 0, int tTime = 0);

  void setCustomerInfo(int customerN = 0, int inTime = 0, int wTime = 0, int tTime = 0)
  {
      int customerNumber = customerN;
      int arrivalTime = inTime;
      int waitingtime = wTime;
      int transactionTime = tTime;
  }
  void customerType(int customerN, int inTime, int wTime, int tTime)
  {
    setCustomerInfo(customerN,inTime,wTime,tTime);
  }

  int getWaitingTime()
  {
    return waitingTime;
  }
  void setWaitingTime(int wTime)
  {
    waitingTime = wTime;
  }
  void incrementWaitingTime()
  {
    waitingTime++;
  }
  int getArrivalTime()
  {
    return arrivalTime;
  }
  int getTransactionTime()
  {
    return transactionTime;
  }
  int getCustomerNumber()
  {
    return customerNumber;
  }
private:
  int customerNumber;
  int arrivalTime;
  int waitingTime;
  int transactionTime;

};

