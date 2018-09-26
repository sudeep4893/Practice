CREATE OR REPLACE PROCEDURE dispEmployee(job in varchar)
 IS 
     no            NUMBER; 
     nm           VARCHAR2(30); 
     cid           INTEGER; 
     n             INTEGER; 

     str  	varchar(100);	
BEGIN 
   
     cid := dbms_sql.open_cursor; 
     str := 'select eno, ename from emp where ejob =  :j ';

     DBMS_SQL.PARSE(cid, str , DBMS_SQL.NATIVE); 
     DBMS_SQL.BIND_VARIABLE(cid,':j', job); 

     DBMS_SQL.DEFINE_COLUMN(cid, 1, no); 
     DBMS_SQL.DEFINE_COLUMN(cid, 2, nm, 30); 

     n := DBMS_SQL.EXECUTE(cid); 
 
  -- Fetch a row from the table 
     LOOP 
       IF DBMS_SQL.FETCH_ROWS(cid) > 0 THEN 
         -- get column values of the row 
         DBMS_SQL.COLUMN_VALUE(cid , 1, no); 
         DBMS_SQL.COLUMN_VALUE(cid, 2, nm); 

         DBMS_OUTPUT.PUT_LINE(no || '  ' || nm);	 

      ELSE 
        EXIT; 
      END IF; 

    END LOOP; 
 
     DBMS_SQL.CLOSE_CURSOR(cid); 
   EXCEPTION 
     WHEN OTHERS THEN 
       IF DBMS_SQL.IS_OPEN(cid) THEN 
         DBMS_SQL.CLOSE_CURSOR(cid); 
       END IF; 
  END; 
/ 
