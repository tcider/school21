envsubst '${WP_PORT}' < default.conf.tmp > default.conf
mv default.conf /etc/nginx/conf.d/
envsubst '${MYSQL_USER} ${MYSQL_PASW}' < wp-config.php.tmp > wp-config.php
mv wp-config.php /var/www/wordpress/wp-config.php
mysql -u $MYSQL_USER --password=$MYSQL_PASW -h mysql-service < wordpress.sql
nginx
/usr/sbin/php-fpm7 -F
