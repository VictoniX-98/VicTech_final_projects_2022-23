function initMap() {
    // Ofice location 
    our_latitude = parseFloat(our_latitude);
    our_latitude = parseFloat(our_longitude)
    var ofice_location = {lat: our_latitude, lng: our_longitude}

    // Accident location
    latitude = parseFloat(latitude);
    longitude = parseFloat(longitude);
    var location = {lat: latitude, lng: longitude};

    var options = {
        center: ofice_location,
        zoom: 12
    };

    let map = new google.maps.Map(document.getElementById('map'), options);
    
    let office_mark = new google.maps.Marker({
        position: ofice_location,
        map: map,
    });
    let accident_mark = new google.maps.Marker({
        position: location,
        map: map,
    });

    let info1 = new google.maps.InfoWindow({
        content: '<h3>Our Location</h3>',
    });
    let info2 = new google.maps.InfoWindow({
        content: '<h3>Accident area</h3>',
    });

    office_mark.addListener('mouseover', function(){
        info1.open(map, office_mark);
    });
    
    accident_mark.addListener('mouseover', function(){
        info2.open(map, accident_mark);
    });
}