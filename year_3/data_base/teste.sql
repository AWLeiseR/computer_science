BEGIN;
	ALTER TABLE revista.userareas DROP CONSTRAINT  fkuserareasuser ;
	ALTER TABLE revista.userareas ADD  CONSTRAINT fkuserareasuser FOREIGN KEY (iduser) 
		 REFERENCES revista.users(userid)
		ON DELETE CASCADE
		ON UPDATE CASCADE;
COMMIT;
ALTER TABLE revista.highlights
alter CONSTRAINT constraint_fk
FOREIGN KEY (fk_columns)
REFERENCES parent_table(parent_key_columns)

DELETE FROM revista.users  WHERE userid =47;