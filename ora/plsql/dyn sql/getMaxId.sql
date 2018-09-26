create or replace function getMaxId(x varchar, y varchar) return number
IS
str varchar(80);
n number;

q INTEGER;
cid INTEGER;

BEGIN
str := 'select max(' || x || ') from ' || y;

cid := DBMS_SQL.OPEN_CURSOR;

DBMS_SQL.PARSE(cid, str, DBMS_SQL.NATIVE);

DBMS_SQL.DEFINE_COLUMN(cid,1, n );

q := DBMS_SQL.EXECUTE(cid);

IF DBMS_SQL.FETCH_ROWS(cid) > 0 THEN
     DBMS_SQL.COLUMN_VALUE(cid, 1, n); 
ELSE
     n:=0;
END IF;

DBMS_SQL.CLOSE_CURSOR(cid);

return n; 

EXCEPTION
 WHEN OTHERS THEN
   DBMS_SQL.CLOSE_CURSOR(cid);
   return 0;

END;
/