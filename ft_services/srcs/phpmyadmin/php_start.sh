envsubst '${PMA_PORT}' < default.conf.tmp > default.conf
mv default.conf /etc/nginx/conf.d/
envsubst '${MYSQL_PORT} ${MYSQL_USER} ${MYSQL_PASW}' < config.inc.php.tmp > config.inc.php
mv config.inc.php /usr/share/phpmyadmin/config.inc.php

nginx
/usr/sbin/php-fpm7 -F
