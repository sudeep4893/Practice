CREATE OR REPLACE PROCEDURE dropTable(tabname IN varchar) 
AS

   cid INTEGER;
   str varchar2(100);
BEGIN
   cid := DBMS_SQL.OPEN_CURSOR;
  
   --DDL statements are run by the parse call, 
   --which performs the implied commit.

   str := 'drop table ' || tabname;
   DBMS_SQL.PARSE(cid, str, DBMS_SQL.NATIVE);
   
   DBMS_SQL.CLOSE_CURSOR(cid);

END;
/