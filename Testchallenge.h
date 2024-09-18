// void alertInCelcius(float farenheit);
// int getfailurecount();

//Abstraction using class interface
// functionpointer

class INetworkAlerter{
public:
    virtual void alert(float celsius)=0;
};


int alertInCelsiusFacade(float farenheit *networkAlerterPtr);
