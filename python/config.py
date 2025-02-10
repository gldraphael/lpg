
from dynaconf import Dynaconf

settings = Dynaconf(
    envvar_prefix="LPG",
    settings_files=['settings.yaml', '.secrets.yaml'],
)

# `envvar_prefix` = export envvars with `export LPG_FOO=bar`.
# `settings_files` = Load these files in the order.
