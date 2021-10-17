package com.example.myitems;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    private EditText mname ,memail;
    Button button;
    private FirebaseDatabase db= FirebaseDatabase.getInstance();
    private DatabaseReference root=db.getReference().child("Items");





    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mname=findViewById(R.id.mname);
        memail=findViewById(R.id.memail);
        button=findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                String name=mname.getText().toString();
                String email=memail.getText().toString();
                HashMap<String,String> usermap=new HashMap<>();
                usermap.put("Name",name);
                usermap.put("Cost",email);
                root.push().setValue(usermap);
            }
        });
    }
}