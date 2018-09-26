CREATE OR REPLACE PROCEDURE deleteEmployee(salary IN NUMBER) 
AS
    cid INTEGER;
    n INTEGER;    
    str varchar(100);
BEGIN
/*
This example could have been solved using regular
static sql also, but we implement this using dyn sql
for illustration purpose.
The deleteEmployee procedure deletes all of the 
employees from the EMP table whose salaries are greater 
than the salary that you specify when you run procedure.
*/

    cid := dbms_sql.OPEN_CURSOR;
    str := 'delete from emp where esal > :x';
    DBMS_SQL.PARSE(cid, str,  DBMS_SQL.NATIVE);

    DBMS_SQL.BIND_VARIABLE(cid, ':x', salary);

    n := DBMS_SQL.EXECUTE(cid);

    DBMS_OUTPUT.PUT_LINE(n || ' rows deleted ');

    DBMS_SQL.CLOSE_CURSOR(cid);

EXCEPTION
 WHEN OTHERS THEN
    DBMS_SQL.CLOSE_CURSOR(cid);

END;
/