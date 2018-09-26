create or replace trigger MANOJNOTALLOWED
before 
insert
on EMP
for each row

BEGIN
  IF upper(:new.ename) = 'MANOJ' THEN
   raise_application_error(-20001, 'MANOJ NOT ALLOWED HERE');
  END IF;
END;
/