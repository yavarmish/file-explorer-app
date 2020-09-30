
const children=$('tbody').children();

let children_array=[];

for(let i=0;i<children.length;i++)
children_array.push(children[i]);

const items=[];
children_array.forEach(element=>{

    const rowDetails={
        name: element.getAttribute('data-name'),
        size: parseInt(element.getAttribute('data-size')),
        time: parseInt(element.getAttribute('data-time')),
        html: element.outerHTML
    };
    items.push(rowDetails);

});

const sortStatus={
    name:'up',
    size:'up',
    time:'up'
};

const sort_names_up=(items,type)=>{
    items.sort((item1,item2)=>{
        let value1,value2;
        if(type==='name')
        {
             value1 = item1.name.toUpperCase();
             value2 = item2.name.toUpperCase();
            
        }

        else if(type==='size')
        {
            value1 = item1.size;
            value2 = item2.size;
        }

        else
        {
            value1 = item1.time;
            value2 = item2.time;   
        }

        if (value1 < value2)
            return -1;

        else if (value1 > value2)
            return 1;

        return 0;


    });
};

const sort_names_down = (items,type) => {
    sort_names_up(items,type);
    items.reverse();
};

const fill_table_body=items=>{
    const content=items.map(element=>element.html).join('');
    $('tbody').html(content);
}

document.getElementById('table_head_row').addEventListener('click', event => {
    if(event.target)
    {
        
            $('ion-icon').remove();

            let status;
            if (['none', 'down'].includes(sortStatus[event.target.id])) { 
                sort_names_up(items, event.target.id); sortStatus[event.target.id]= 'up';
            event.target.innerHTML +='<ion-icon name="arrow-up-circle"></ion-icon>';

            }
            else if (sortStatus[event.target.id] === 'up') {
                sort_names_down(items, event.target.id); sortStatus[event.target.id]= 'down';
            event.target.innerHTML += '<ion-icon name="arrow-down-circle"></ion-icon>'; }

            fill_table_body(items);   
        



    }

});

// document.getElementById('name').addEventListener('click',()=>{
//     if(['none','down'].includes(sortStatus.name))
//     {sort_names_up(items);sortStatus.name='up';}    
//     else if(sortStatus.name==='up'){sort_names_down(items);sortStatus.name='down';}

//     fill_table_body(items);
// });


