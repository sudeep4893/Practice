create or replace package body emppack
as
  procedure addEmployee(eno number, ename varchar, ejob varchar, esal number, dno number)
  IS
  BEGIN
    insert into emp values(eno, ename, ejob, esal, dno);
    DBMS_OUTPUT.PUT_LINE('Record Inserted');
  
  EXCEPTION
    WHEN OTHERS THEN
     DBMS_OUTPUT.PUT_LINE('Record Insertion FAILED');
  END;
  
  procedure deleteEmployee(en number)
  IS
  BEGIN
    delete from emp where eno = en;
    DBMS_OUTPUT.PUT_LINE( SQL%ROWCOUNT || ' records deleted');
  END;

  procedure updateEmployeeSalaray(en number, es number)
  IS
  BEGIN
    update emp set esal = es where eno = en;
    DBMS_OUTPUT.PUT_LINE( SQL%ROWCOUNT || ' records updated');
  END;

  function getDname(en varchar) return varchar
  IS
   var dept.dname%type;
  BEGIN
     select dname into var from dept
     where dno in 
     ( select dno from emp where ename = en);

     return var;

  EXCEPTION
     WHEN TOO_MANY_ROWS THEN
         return 'multiple employees with name ' || en;
     WHEN NO_DATA_FOUND THEN
         return 'no employee with name ' || en;

  END;

  function getRandomValue(n number) return number
  IS
  BEGIN
    return DBMS_RANDOM.VALUE * n;
  END;

END emppack;
/