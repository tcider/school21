adduser -D $SSH_USER
echo "$SSH_USER:$SSH_PASW" | chpasswd
ssh-keygen -A 
/usr/sbin/sshd
envsubst '${IP} ${PMA_PORT} ${WP_PORT}' < default.conf.tmp > default.conf
mv default.conf /etc/nginx/conf.d/default.conf
nginx -g "daemon off;"
