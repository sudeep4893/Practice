class VegetableVendor
{
 String veg[];
 int rate[];
 int currentV;
 double currentR; 
 VegetableClient vc; 

 VegetableVendor(VegetableClient ref)
 {
   vc = ref;

   veg = new String[5];
   rate = new int[5];

   veg[0] = "potato";
   rate[0] = 30;

   veg[1] = "tomato";
   rate[1] = 40;

   veg[2] = "brinjal";
   rate[2] = 40;

   veg[3] = "spinach";
   rate[3] = 15;

   veg[4] = "onion";
   rate[4] = 25;

 }//VegetableVendor()

 int inquiry(String vegName)
 {//seq search

   int i;
   for(i =0 ; i< veg.length; i++)
   {
     if(veg[i].equalsIgnoreCase(vegName))
     {
       currentV = i;
       currentR = rate[i];
       return rate[i];
     }//if
   }//for  
   return -1;//not found
 }//inquiry

 double discount()
 {
   int q = vc.quantity();  //runtime bound

   double discnt;
   if(q >1 && q <= 5)
     discnt = currentR * 5 / 100;
   else if(q >5 && q <= 10)
     discnt = currentR * 10 / 100;
   else
     discnt = 0;

  currentR -= discnt;
  return discnt;
 }

 void sell()
 {
  System.out.println("Selling " + veg[currentV] + "@ Rs/UNIT " + currentR + " to " + vc.userName);
 }
 
}//VegetableVendor

abstract class VegetableClient
{
 String userName;

 VegetableClient(String x)
 {
   userName = x;
 }

 final void purchaseVegetable()
 {
  VegetableVendor vv = new VegetableVendor(this);
  int p = vv.inquiry("spinach"); 
  if(p != -1)
  {
   double d = vv.discount();
   if(d != 0)
   {
     vv.sell();   
   }
   else
   {
    System.out.println("I didn't got any discout ");
   }
  }
  else
   System.out.println("Vegetable not available");

 }//purchaseVegetable

 abstract int quantity();
}//VegetableClient

class HomeUser extends VegetableClient
{
 HomeUser(String s)
 {
  super(s);
 }

 int quantity()//override
 {
  //... logic here
  System.out.println("HomeUser's approach to decide quantity");
  return 2;
 }
}

class Resto extends VegetableClient
{
 Resto(String s)
 {
  super(s);
 }

 int quantity()//override
 {
  //... logic here
  System.out.println("Resto's approach to decide quantity");
  return 8;
 }
}

class MHall extends VegetableClient
{
 MHall(String s)
 {
  super(s);
 }

 int quantity()//override
 {
  //... logic here
  System.out.println("MHall's approach to decide quantity");
  return 20;
 }
}

class AbstractApplication
{
 public static void main(String args[])
 {
  VegetableClient arr[] = new VegetableClient[3];
  arr[0] = new HomeUser("Vikas");
  arr[1] = new Resto("EatGood");
  arr[2] = new MHall("ComeOnce");

  int i;
  for(i =0 ; i< arr.length; i++)
   arr[i].purchaseVegetable();

 }//main
}//AbstractApplication