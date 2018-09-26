DECLARE
 CURSOR c is 
 select eno, ename from emp;

 var1 emp.eno%type;
 var2 emp.ename%type;
BEGIN
 --DEMO. OF EXPLICIT CURSOR 
 --step 1)
 open c; --opens the cursor (AND SQL of the cursor executes)

 IF c%ISOPEN THEN
    --step 2)
    LOOP
      fetch c into var1, var2;
      EXIT WHEN c%NOTFOUND;      
      --IF mod(var1, 2) = 0 THEN
        DBMS_OUTPUT.PUT_LINE(c%ROWCOUNT ||')  ' ||var1 || '  ' ||var2 );
      --END IF;
    END LOOP;

    --step 3)
    close c; --closes the cursor 
 ELSE
   DBMS_OUTPUT.PUT_LINE('Cursor open failed');
 END IF;

END;
/