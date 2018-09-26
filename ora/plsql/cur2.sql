DECLARE
CURSOR c (x varchar) is
select ename, esal from emp
where ejob = x;

en emp.ename%type;
es emp.esal%type;

ej emp.ejob%type;

BEGIN
  --PARAMETERIZED CURSOR
  ej := '&job';

  IF ej is NULL THEN
   ej := 'manager';
  END IF;

 open c(ej);--pass parameter to a cusror

 IF c%ISOPEN THEN
   LOOP 
     fetch c into en, es;  
     EXIT WHEN c%NOTFOUND;
     DBMS_OUTPUT.PUT_LINE(NVL(en, 'NO NAME') || '  ' || es);
   END LOOP;
   close c;
 ELSE
   DBMS_OUTPUT.PUT_LINE('cursor open failed');
 END IF;

END;
/