DECLARE
 var emp.eno%type;
 record emp%rowtype;

 NEGATIVE_ENO EXCEPTION; 
BEGIN
 var := &empNo;

 IF var < 0 THEN --detect a logically wrong case
   RAISE NEGATIVE_ENO; -- generate an exception
 END IF;

--observe the compulsory use of into clause and
--variable(s) for select statement in PLSQL block

 select * into record from emp
 where eno = var;

--NOTE THE GENEARATION OF EXCEPTIONS 
--IN CASE : MULTIPLE ROWS FOUND
--IN CASE : NO ROWS FOUND
 DBMS_OUTPUT.PUT_LINE(record.eno ||'  '|| record.ename ||'  '|| record.ejob ||'  '|| record.esal ||'  '|| record.dno);


EXCEPTION
 WHEN NO_DATA_FOUND THEN
   DBMS_OUTPUT.PUT_LINE('Record for eno : ' || var || ' is not found');
 WHEN TOO_MANY_ROWS THEN
   DBMS_OUTPUT.PUT_LINE('MULTIPLE Record for eno : ' || var || ' are found');
 WHEN NEGATIVE_ENO THEN   
   DBMS_OUTPUT.PUT_LINE('NEGATIVE eno : ' || var || ' not allowed ');
 WHEN OTHERS THEN   
   DBMS_OUTPUT.PUT_LINE('I HANDLE ALL SEEN/UNSEEN EXCEPTIONS');

END;
/