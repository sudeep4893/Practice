create or replace function add3nos(n IN number, m IN number, o IN number)
return number 
IS

  result number;

BEGIN

 result := n+ m+o ;
 return result;

END;
/
 

