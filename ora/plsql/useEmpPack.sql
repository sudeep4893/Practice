DECLARE
  dn varchar(30);
BEGIN
  --package.procedure

  DBMS_OUTPUT.PUT_LINE('ADDING EMP 83 ');
  emppack.addEmployee(83, 'qq', 'manager', 12121, 3);

  DBMS_OUTPUT.PUT_LINE('DELETING EMP 77 ');
  emppack.deleteEmployee(77);

  DBMS_OUTPUT.PUT_LINE('UPDATING SAL OF EMP 65 ');
  emppack.updateEmployeeSalaray(65, 1010);

  --package.function
  DBMS_OUTPUT.PUT('DNAME OF VIJAY : ');
  dn := emppack.getDname('VIJAY');
  DBMS_OUTPUT.PUT_LINE( dn);

 --package.variable  
  DBMS_OUTPUT.PUT('RANDOM NUMBER IN RANGE 0 to 100 : ');
  emppack.globalVar := emppack.getRandomValue(100);
  DBMS_OUTPUT.PUT_LINE(emppack.globalVar);


END;
/