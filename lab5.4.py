from netmiko import ConnectHandler

myserver = {
    'device_type': 'linux',
    'host':   '192.168.56.4',  #Your Server IP
    'username': 'qilazainuddin', #your Server Username
    'password': 'No@827632', #your server password
    'port' : 22,
    'secret': '',
}

net_connect = ConnectHandler(**myserver)
output = net_connect.send_command('uname -a')
print(output)
