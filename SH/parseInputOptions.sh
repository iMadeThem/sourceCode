#!/bin/sh

client_id=`cat .client_id`
sample_client_id="dljkajkduull234ulj98f8448wqkjfp"
operation="remove"

if [ $# -ge 1 ]; then
    case $1 in
        --help|-h)
            echo "$0 <options>"
            echo "--help,-h    show this help"
            echo "--add,-a     add client key"
            echo ""
            echo "replace specific client key in the project to place holder CLIENT_ID."
            echo "use --add or -a to do the reverse. client key is saved in '.client_id'"
            exit 0
                ;;
        --add|-a)
            operation=add
                ;;
    esac
fi

target_files="file_1 file_2 file_3"

case $operation in
    remove)
        for target in $target_files
        do
            sed -i -e "s/$client_id/$sample_client_id/g" $target
        done
        ;;
    add)
        for target in $target_files
        do
            sed -i -e "s/$sample_client_id/$client_id/g" $target
        done
        ;;
esac
