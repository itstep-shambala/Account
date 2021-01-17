create table table_account
(
	id integer not null
		constraint table_account_pk
			primary key autoincrement,
	login text not null,
	password text not null,
	is_active integer default 1 not null
);

create table table_person
(
	id integer not null
		constraint table_person_pk
			primary key autoincrement
		constraint table_person_table_account_id_fk
			references table_account,
	first_name text not null,
	last_name text not null,
	birth_day text not null,
	email text not null,
	tel text not null
);

create table table_role
(
	id integer not null
		constraint table_role_pk
			primary key autoincrement,
	role text not null
);

create table table_account_role
(
	id integer not null
		constraint table_account_role_pk
			primary key autoincrement,
	account_id int not null,
	role_id int not null
);

INSERT INTO table_account (login, password)
VALUES ('admin', '12345');
INSERT INTO table_account (login, password)
VALUES ('guest', '123');
INSERT INTO table_account (login, password, is_active)
VALUES ('adm', '0000', 0);

INSERT INTO table_person (first_name, last_name, birth_day, email, tel)
VALUES ('Admin', 'Admin', '2020-12-20', 'admin@admin.admin', '+7 (123) 123-45-67');
INSERT INTO table_person (first_name, last_name, birth_day, email, tel)
VALUES ('Guest', 'Guest', '2020-12-20', 'guest@guest.guest', '+7 (123) 123-45-67');
INSERT INTO table_person (first_name, last_name, birth_day, email, tel)
VALUES ('Adm', 'Adm', '2020-12-19', 'adm@adm.adm', '+71231234567');

INSERT INTO table_role (role) VALUES ('admin');
INSERT INTO table_role (role) VALUES ('user');
INSERT INTO table_role (role) VALUES ('guest');

INSERT INTO table_account_role (account_id, role_id)
VALUES (1, 1);
INSERT INTO table_account_role (account_id, role_id)
VALUES (2, 2);
INSERT INTO table_account_role (account_id, role_id)
VALUES (2, 3);
INSERT INTO table_account_role (account_id, role_id)
VALUES (3, 1);
