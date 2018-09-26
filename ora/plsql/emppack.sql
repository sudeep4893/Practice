create or replace package emppack
as
  procedure addEmployee(eno number, ename varchar, ejob varchar, esal number, dno number);
  procedure deleteEmployee(en number);
  procedure updateEmployeeSalaray(en number, es number);
  function getDname(en varchar) return varchar;
  function getRandomValue(n number) return number;
  globalVar number;
END emppack;
/