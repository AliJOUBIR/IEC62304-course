#define AIR_LIGHT 0
#define HUM_TEMP 1
#define ALARM 2

void setup()
{

}

int button_click()
{
    return digitalRead(BUTTON);
}

int gas_measure()
{
    int gas_mears;
    /* gas */
    return gas_mears; /*0 100 , 80 mean danger*/ 
}
int count = 0;
int gas_deteted()
{
    int gas;
    
    /* gas */
    if ((gas_measure() > 80) && (count < 20))
    {
        count++;
    }
    if (count >= 20)
        gas = 1;
    if (gas_measure() < 80)
    {
        gas = 0;
        count = 0;
    }
    return gas;
}

int gas_low()
{
    int gas;
    /* gas */
    return gas;
}

int gas_out_time = 0;
unsigned long time = 0;
unsigned long pre_time = 0;

int state_sensor = 0;
void loop()
{

    time = millis();
    if (time - pre_time > 100)
    {
        pre_time = time;
    }
    else
    {
        return;
    }

    switch (state_sensor)
    {
    case AIR_LIGHT:
        if (button_click() == true)
        {
            state_sensor = HUM_TEMP;
        }
        if (gas_deteted())
        {
            state_sensor = ALARM;
        }
        break;
    case HUM_TEMP:
        if (button_click() == 1)
        {
            state_sensor = AIR_LIGHT;
        }
        if (gas_deteted())
        {
            state_sensor = ALARM;
        }
        break;
    case ALARM:
        if (gas_low())
        {
            gas_out_time+=1;
        }
        else
        {
            gas_out_time = 0;
        }
        if (gas_out_time > 10)
        {
            state_sensor = AIR_LIGHT;
        }
        break;    
    default:
        break;
    }

}