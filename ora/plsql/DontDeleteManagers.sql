create or replace trigger DontDeleteManagers
before
delete 
on emp
for each row

BEGIN
   IF upper(:old.ejob) = upper('manager') THEN
     raise_application_error(-20001, 'Manager Cannot Be Deleted');
   END IF;

END;
/