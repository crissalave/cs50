import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

TABLE_NAME = "birthdays"


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get('personName')
        month = request.form.get('month')
        day = request.form.get('day')

        db.execute("INSERT INTO ? ('name', 'month', 'day') VALUES (?, ?, ?)", TABLE_NAME, name, month, day)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        list = db.execute("SELECT * FROM ?", TABLE_NAME)

        return render_template("index.html", birthdayList=list)

@app.post("/d")
def delete():
    id = request.form.get("id")
    db.execute("DELETE FROM ? WHERE id = ?", TABLE_NAME, id)

    return redirect("/")
