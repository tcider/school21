envsubst '${MYSQL_PORT} ${MYSQL_USER} ${MYSQL_PASW}' < my.cnf.tmp > my.cnf
mv my.cnf /etc/my.cnf
envsubst '${MYSQL_USER} ${MYSQL_PASW}' < mysql.sql.tmp > mysql.sql
mysql_install_db --user=$MYSQL_USER --ldata=/var/lib/mysql
/usr/bin/mysqld --user=$MYSQL_USER --datadir='/var/lib/mysql' --init_file=/tmp/mysql.sql
