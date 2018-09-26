create or replace procedure printName(en number)
IS
  str varchar(50);   
  nm varchar(50);   
  q INTEGER;
  cid INTEGER;

BEGIN
  str := 'select ename from emp where eno = :x';  

  cid := DBMS_SQL.OPEN_CURSOR;

  DBMS_SQL.PARSE(cid, str, DBMS_SQL.NATIVE);

  DBMS_SQL.BIND_VARIABLE(cid, ':x' , en);

  DBMS_SQL.DEFINE_COLUMN(cid, 1, nm, 50);

  q := DBMS_SQL.EXECUTE(cid);  

  IF DBMS_SQL.FETCH_ROWS(cid) > 0 THEN
    DBMS_SQL.COLUMN_VALUE(cid, 1, nm);
  ELSE
    nm := 'not found';
  END IF;

  DBMS_OUTPUT.PUT_LINE('name of employee number ' || en  || ' is ' || nm);

  DBMS_SQL.CLOSE_CURSOR(cid);

EXCEPTION
  WHEN OTHERS THEN
    DBMS_SQL.CLOSE_CURSOR(cid);    
    DBMS_OUTPUT.PUT_LINE('name of employee number ' || en  || ' is not found');
    
END;
/
