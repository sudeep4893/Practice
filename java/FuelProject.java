class Fuel
{
 private String fuelName;
 private int fuelPrice;
 
 Fuel(String fn, int fp)
 {
  fuelName = fn;
  fuelPrice = fp;
 }
 
 public int getFuelPrice()//getter or accessor  method
 {
  return fuelPrice;
 }

 public String getFuelName()//getter or accessor  method
 {
  return fuelName;
 }

}//Fuel

class FuelTank
{
 Fuel f;
 private int qty;

 FuelTank(String fName, int fPrice, int q)
 {
  f = new Fuel(fName, fPrice);
  qty = q;
 }

 void addFuel(int x)
 {
  qty += x;
 }

 void removeFuel(int x)
 {
  qty -= x;
 }

 int getQty()
 {
   return qty;
 }
}

interface FuelUser
{
 String whichFuel();
 int howMuch();
}

class FuelStation
{
 FuelTank arr[];
 static final int NOTFOUND = -1;

 FuelStation()
 {
  arr = new FuelTank[3];
  arr[0] = new FuelTank("Petrol", 81, 10000);
  arr[1] = new FuelTank("Diesel", 60, 15000);
  arr[2] = new FuelTank("LPG", 41, 5000);
 }

 int search(String fn)
 {//sequential search
  int i;
  String temp;

  for(i =0; i< arr.length; i++)
  {
   temp = arr[i].f.getFuelName();
   if(temp.equalsIgnoreCase(fn))
   {
      return i;//tankIndex
   }
  }//for
  return NOTFOUND;
 }//search

 void sellFuel(FuelUser fu)
 {
  String fn = fu.whichFuel(); 
  int tankIndex = search(fn);
  if(tankIndex != NOTFOUND)
  {
    int reqdQ = fu.howMuch();
    int availableQ = arr[tankIndex].getQty();
    if(reqdQ <= availableQ)  
    {
      //...
      arr[tankIndex].removeFuel(reqdQ);
      //bill
      int p = arr[tankIndex].f.getFuelPrice();
      int billAmt = p * reqdQ;
      System.out.println("=======BILL========");
      System.out.println("Thank You for Purchasing "+ reqdQ + " liters of " + fn); 
      System.out.println("Your Bill Amount : Rs. "+ billAmt);
      System.out.println(" Drive Safe ");
      System.out.println("==================");
    }
    else
    {
     System.out.println("==================");
     System.out.println("Sorry we dont have "+ reqdQ + " liters of " + fn); 
     System.out.println("==================");
    }
  }
  else
  {
     System.out.println("==================");
     System.out.println("Sorry we dont sell "+ fn); 
     System.out.println("==================");
  }
 }

}//FuelStation

class Bike implements FuelUser
{
 void fillFuel(FuelStation fs)
 {
  fs.sellFuel(this);
 }

 public String whichFuel()
 {
  //...
  return "petrol";
 }

 public int howMuch()
 {
  //....
  return 3;
 }
}//Bike

class Car implements FuelUser
{
 String ftype;
 Car(String s)
 {
   ftype = s;
 }

 void fillFuel(FuelStation fs)
 {
  fs.sellFuel(this);
 }

 public String whichFuel()
 {
  return ftype;
 }

 public int howMuch()
 {
  //....
  return 10;
 }
}//Car


class ARickshaw implements FuelUser
{
 void fillFuel(FuelStation fs)
 {
  fs.sellFuel(this);
 }

 public String whichFuel()
 {
  //...
  return "CNG";
 }

 public int howMuch()
 {
  //....
  return 3;
 }
}//ARickshaw

class FuelProject
{
 public static void main(String args[])
 {
  FuelStation fs = new FuelStation();
  Bike b = new Bike(); 
  Car c1 = new Car("petrol");
  Car c2 = new Car("diesel");
  ARickshaw ar =  new ARickshaw();

  b.fillFuel(fs); 
  c1.fillFuel(fs); 
  c2.fillFuel(fs); 
  ar.fillFuel(fs);
 }//main
}//FuelProject