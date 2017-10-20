#include "xml.h"
#include "mainwindow.h"

TypeChange TYPE;

int XmlContainer::writeXml(struct Camera_config *config_struct)
{
    QFile file("config.xml");//(":/myconfig/resource/config.xml");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();
            writer.writeStartElement("Config");
                writer.writeStartElement("usrConfig");
                    writer.writeTextElement("usrName", TYPE.stringToChar(config_struct->usrName,sizeof( config_struct->usrName)));
                    writer.writeTextElement("usrPassword", TYPE.stringToChar(config_struct->usrPassword,sizeof( config_struct->usrPassword)));
                    writer.writeTextElement("managerName", TYPE.stringToChar(config_struct->managerName,sizeof( config_struct->managerName)));
                    writer.writeTextElement("managerPassword", TYPE.stringToChar(config_struct->managerPassword,sizeof( config_struct->managerPassword)));
                 writer.writeEndElement();

            writer.writeEndElement();
        writer.writeEndElement();
        file.close();
    }
    return 0;
}

int XmlContainer::readXml(Camera_config *read_struct)
{
    QDomDocument doc;
    QFile file("config.xml");
    QString error = "";
    //bool ok;
    int row = 0, column = 0;
    if (!file.open(QIODevice::ReadOnly))
    {
        return -2;
    }

    if(!doc.setContent(&file, false, &error, &row, &column))
    {
        qDebug() << "parse file failed:" << row << "---" << column <<":" <<error;
        file.close();
        return -1;
    }

    file.close();
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChildElement();
    while(!node.isNull()) {
       QDomElement element = node.toElement(); // try to convert the node to an element.
       if(!element.isNull())
       {
           if (element.tagName() == "usrConfig")
           {
                QDomNodeList list = element.childNodes();
                for(int index = 0; index < list.count(); index++)
                {
                    QDomNode list_node = list.item(index);
                    QDomElement list_element = list_node.toElement();
                    if (list_element.tagName() =="usrName")
                    {
                         read_struct->usrName=list_element.text().toStdString();
                         //QString qstr2 = QString::fromStdString(read_struct->usrName);
                         //qDebug("readString = %s",qPrintable(qstr2));
                    }
                    if (list_element.tagName() =="usrPassword")
                    {
                         read_struct->usrPassword=list_element.text().toStdString();
                    }
                    if (list_element.tagName() =="managerName")
                    {
                         read_struct->managerName=list_element.text().toStdString();
                    }
                    if (list_element.tagName() =="managerPassword")
                    {
                         read_struct->managerPassword=list_element.text().toStdString();
                    }
                }
           }

       }
       node = node.nextSibling();
    }
    return 0 ;
}
