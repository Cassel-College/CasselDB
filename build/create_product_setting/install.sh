# write install path to /etc/profile

# get install path

echo "Get install path from configuration..."

CASSELDB_INSTALL_PATH=$(cat ./configuration.config | grep "install_path")

# write path to /etc/profile

info="CASSELDB_INSTALL_PATH="${CASSELDB_INSTALL_PATH#*=}
