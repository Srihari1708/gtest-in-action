// void alertInCelcius(float farenheit);
// int getfailurecount();

//Abstraction using class interface
// functionpointer

class INetworkAlerter{
public:
    virtual int alert(float celsius)=0;
};


int alertInCelsiusFacade(float farenheit, INetworkAlerter *networkAlerterPtr);
